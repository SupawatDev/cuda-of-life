#ifdef __CUDACC__
#define CUDA_CALLABLE_MEMBER __host__ __device__
#else
#define CUDA_CALLABLE_MEMBER
#endif 

#ifndef LAW_H_
#define LAW_H_

class Law {
public:
    CUDA_CALLABLE_MEMBER Law() {}
    CUDA_CALLABLE_MEMBER ~Law() {}
    CUDA_CALLABLE_MEMBER void aMethod() {}
private: 

};
#endif