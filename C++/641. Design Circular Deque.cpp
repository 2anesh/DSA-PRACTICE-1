class MyCircularDeque {
private:
    vector <int> cdq;
    int front=-1;
    int rear=-1;
    int m;
public:
    MyCircularDeque(int k) {
        cdq.resize(k);
        m=k;
    }   
    bool insertFront(int value) {
        if((rear+1)%m==front)
            return false;
        else
        {
            if(rear==-1 && front==-1)
            {
                rear=0;
                front=0;
                cdq[front]=value;
            }
            else
            {
                front=(front-1+m)%m;
                cdq[front]=value;
            }
            return true;
        }
    }    
    bool insertLast(int value) {
            if((rear+1)%m==front)
                return false;
            else
            {
                if(rear==-1 && front==-1)
                {
                    rear=0;
                    front=0;
                    cdq[rear]=value;
                }
                else
                {
                    rear=(rear+1)%m;
                    cdq[rear]=value;
                }
                return true;
            }   
    }    
    bool deleteFront() {
        if(rear==-1 && front==-1)
            return false;
        else
        {
            if(rear==front)
            {
                rear=-1;
                front=-1;
            }
            else
            {
                front=(front+1)%m;
            }
            return true;
        }
    }    
    bool deleteLast() {
        if(rear==-1 && front==-1)
            return false;
        else
        {
            if(rear==front)
            {
                rear=-1;
                front=-1;
            }
            else
            {
                rear=(rear-1+m)%m;
            }
            return true;
        }
    }    
    int getFront() {
        if(rear==-1 && front==-1)
            return -1;
        else
            return cdq[front];
    }    
    int getRear() {
        if(rear==-1 && front==-1)
            return -1;
        else
            return cdq[rear];
    }    
    bool isEmpty() {
        if(rear==-1 && front==-1)
            return true;
        else 
            return false;
    }    
    bool isFull() {
        if((rear+1)%m==front)
            return true;
        else
            return false;
    }
};
