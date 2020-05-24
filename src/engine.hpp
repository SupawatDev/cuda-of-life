#ifndef ENGINE_H_
#define ENGINE_H_
class CudaOfLife;
class Engine{
    public:
        Engine(int argc, char** argv);
        ~Engine();
        void Run();
    private:
        static CudaOfLife * cof;
        static void WindowResize(int w, int h);
        static void renderScene(void);
        static void OnKeyboard(unsigned char key, int x, int y);
        static float w;
        static float s;
        static float m;
        static float r;
        static float px;
        static float py;
        static int window_id;
        static float timer;
};
#endif