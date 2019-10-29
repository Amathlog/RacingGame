#pragma once

template<typename T>
class Singleton
{
public:

    static bool HasInstance()
    {
        return ms_instance != nullptr;
    }
    
    static T* GetInstance()
    {
        if (ms_instance == nullptr)
            ms_instance = new T();
        return ms_instance;
    }

    ~Singleton()
    {
        delete ms_instance;
        ms_instance = nullptr;
    }
private:
    Singleton() = default;
    static T* ms_instance;
};