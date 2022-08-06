//
// Created by l1nkkk on 2022/4/1.
//
#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>
#include <functional>
#include <atomic>
#include <future>

using namespace std;


namespace tdemo4{
thread_local int tid_s;
class ThreadPool{
public:
    ThreadPool(int sz):idleNum_(sz), closeSig(sz), futures(sz){
        for(int i = 0; i < sz; ++i){
            futures[i] = closeSig[i].get_future();
            pool_.emplace_back(run, this, std::ref(closeSig[i]));
        }
    }
    static void run(void *args, promise<int> &p){
        ThreadPool* tpool = static_cast<ThreadPool*>(args);
        std::unique_lock<std::mutex> lw(tpool->mu_);
        tid_s = curID++;
        cout << "Init thread: " << tid_s << endl;
        // 调度
        while(!tpool->stopping){
            while(!tpool->stopping && tpool->tasks_.empty()){
                tpool->cond_.wait_for(lw, std::chrono::milliseconds(300));
            };
            if(tpool->stopping) {
                p.set_value(tid_s);
                cout << "thread " << tid_s << " exit" << endl;
                return;
            }

            auto task = tpool->tasks_.front();
            tpool->tasks_.pop();
            lw.unlock();
            // 执行任务
            --tpool->idleNum_;
            task();
            ++tpool->idleNum_;

            lw.lock();
            cout << "task done by " << tid_s << endl;
        }
        p.set_value(tid_s);
    }
    ~ThreadPool(){

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        stop();
//        std::unique_lock<std::mutex> lw(mu_);
        for(auto& t : futures){
            int ind = t.get();
//            cout << "future: " << ind << endl;
            if(pool_[ind].joinable())
                pool_[ind].join();
        }
    }
    void commitTask(function<void()> cb){
        std::unique_lock<std::mutex> lw(mu_);
        cout << "commitTask " <<endl;
        this->tasks_.push(cb);
        cond_.notify_one();
    }

    void stop(){

        std::unique_lock<std::mutex> lw(mu_);
        cout << "stopping" << endl;
        stopping = true;
        cond_.notify_all();
    }

    int idleNum(){
        return idleNum_;
    }

private:
    std::mutex mu_;
    std::condition_variable cond_;
    vector<std::promise<int>> closeSig;
    vector<std::future<int>> futures;
    std::queue<function<void()>> tasks_;
    std::vector<std::thread> pool_;
    atomic<int> idleNum_{0};
    bool stopping = false;
    static int curID;
};
int ThreadPool::curID = 0;
}

void f1(){
    cout << "test 1" << endl;
}

void f2(string a){
    cout << "test " << a << endl;
}


int main(){
    tdemo4::ThreadPool t(8);
    t.commitTask(f1);
    t.commitTask(f1);
    t.commitTask(bind(f2,"2"));
    t.commitTask(bind(f2,"2"));
    t.commitTask(bind(f2,"2"));


    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
}

