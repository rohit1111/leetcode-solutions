class FooBar {
private:
    int n;
    std::mutex mtx;
    std::condition_variable cv;
    int turn=1;
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock,[&](){return turn==1;});        
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            turn=2;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock,[&](){return turn==2;}); 
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            turn=1;
            cv.notify_all();
        }
    }
};