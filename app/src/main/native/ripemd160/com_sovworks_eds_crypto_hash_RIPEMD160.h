/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_sovworks_eds_crypto_hash_RIPEMD160 */

#ifndef _Included_com_sovworks_eds_crypto_hash_RIPEMD160
#define _Included_com_sovworks_eds_crypto_hash_RIPEMD160
#ifdef __cplusplus
extern "C" {
#endif
#undef com_sovworks_eds_crypto_hash_RIPEMD160_INITIAL
#define com_sovworks_eds_crypto_hash_RIPEMD160_INITIAL 0L
#undef com_sovworks_eds_crypto_hash_RIPEMD160_IN_PROGRESS
#define com_sovworks_eds_crypto_hash_RIPEMD160_IN_PROGRESS 1L
#undef com_sovworks_eds_crypto_hash_RIPEMD160_DIGEST_LENGTH
#define com_sovworks_eds_crypto_hash_RIPEMD160_DIGEST_LENGTH 20L
/*
 * Class:     com_sovworks_eds_crypto_hash_RIPEMD160
 * Method:    initContext
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_sovworks_eds_crypto_hash_RIPEMD160_initContext
  (JNIEnv *, jobject);

/*
 * Class:     com_sovworks_eds_crypto_hash_RIPEMD160
 * Method:    freeContext
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_sovworks_eds_crypto_hash_RIPEMD160_freeContext
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_sovworks_eds_crypto_hash_RIPEMD160
 * Method:    resetDigest
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_sovworks_eds_crypto_hash_RIPEMD160_resetDigest
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_sovworks_eds_crypto_hash_RIPEMD160
 * Method:    updateDigestByte
 * Signature: (JB)V
 */
JNIEXPORT void JNICALL Java_com_sovworks_eds_crypto_hash_RIPEMD160_updateDigestByte
  (JNIEnv *, jobject, jlong, jbyte);

/*
 * Class:     com_sovworks_eds_crypto_hash_RIPEMD160
 * Method:    updateDigest
 * Signature: (J[BII)V
 */
JNIEXPORT void JNICALL Java_com_sovworks_eds_crypto_hash_RIPEMD160_updateDigest
  (JNIEnv *, jobject, jlong, jbyteArray, jint, jint);

/*
 * Class:     com_sovworks_eds_crypto_hash_RIPEMD160
 * Method:    finishDigest
 * Signature: (J[B)V
 */
JNIEXPORT void JNICALL Java_com_sovworks_eds_crypto_hash_RIPEMD160_finishDigest
  (JNIEnv *, jobject, jlong, jbyteArray);

#ifdef __cplusplus
}
#endif
#endif
