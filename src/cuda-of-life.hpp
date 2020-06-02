#ifndef APP_H_
#define APP_H_

class CudaOfLife{
    public:
        CudaOfLife();
        void CPU();
        bool GetCell(int x, int y); 
    private:
        bool universe[1000][1000];

};
#endif