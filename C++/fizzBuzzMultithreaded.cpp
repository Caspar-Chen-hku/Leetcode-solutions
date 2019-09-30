class FizzBuzz {
private:
    int n;
    mutex m;
    condition_variable cv;
    bool readythree = false;
    bool readyfive = false;
    bool readynumber = true;
    
public:
    
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for (int i=3; i<=n; i+=3){
            if (i%5==0) continue;
            unique_lock<mutex> lk(m);
            cv.wait(lk, [this]{return readythree&&!readyfive;});
            
            printFizz();
            
            readythree = false;
            readynumber = true;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for (int i=5; i<=n; i+=5){
            if (i%3==0) continue;
            unique_lock<mutex> lk(m);
            cv.wait(lk, [this]{return readyfive&&!readythree;});
            
            printBuzz();
            
            readyfive = false;
            readynumber = true;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for (int i=15; i<=n; i+=15){
            unique_lock<mutex> lk(m);
            cv.wait(lk, [this]{return readyfive&&readythree;});
            
            printFizzBuzz();
            
            readyfive = false;
            readythree = false;
            readynumber = true;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for (int i=1; i<=n; i++){
            unique_lock<mutex> lk(m);
            cv.wait(lk, [this]{return readynumber;});
            
            if (i%3==0){
                readythree = true;
                readynumber = false;
            }
            if (i%5==0){
                readyfive = true;
                readynumber = false;
            }
            if (!readythree && !readyfive){
                printNumber(i);
            }
            cv.notify_all();
        }
    }
};