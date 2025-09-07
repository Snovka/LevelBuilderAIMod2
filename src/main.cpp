#include <jni.h>
#include <android/log.h>

#define LOG_TAG "LevelBuilderAIStub"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

// Викликається при завантаженні бібліотеки
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    LOGI("LevelBuilderAI (Stub) запущено!");
    LOGI("Це лише заглушка. Завантажте повну версію з GitHub: https://github.com/Snovka999/LevelBuilderAIMod2");
    return JNI_VERSION_1_6; 
}