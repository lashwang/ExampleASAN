#include <jni.h>
#include <string>
#include <android/log.h>

using namespace std;

class myexception: public exception
{
    virtual const char* what() const throw()
    {
        return "My exception happened";
    }
} myex;



extern "C"
JNIEXPORT jstring JNICALL
Java_com_gpxblog_exampleasan_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    char *memory_leak = (char *)malloc(1000);
    try
    {
        throw myex;
    }
    catch (exception& e)
    {
        __android_log_print(ANDROID_LOG_INFO,"test","get exeption:%s",e.what());
    }


    return env->NewStringUTF(hello.c_str());
}
