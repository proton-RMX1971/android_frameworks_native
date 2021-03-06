/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @addtogroup AHardwareBuffer
 * @{
 */

/**
 * @file hardware_buffer_jni.h
 * @brief JNI glue for native hardware buffers.
 */

#ifndef ANDROID_HARDWARE_BUFFER_JNI_H
#define ANDROID_HARDWARE_BUFFER_JNI_H

#include <sys/cdefs.h>

#include <android/hardware_buffer.h>

#include <jni.h>

__BEGIN_DECLS

/**
 * Return the AHardwareBuffer wrapped by a Java HardwareBuffer object.
 *
 * This method does not acquire any additional reference to the AHardwareBuffer
 * that is returned. To keep the AHardwareBuffer alive after the Java
 * HardwareBuffer object is closed, explicitly or by the garbage collector, be
 * sure to use AHardwareBuffer_acquire() to acquire an additional reference.
 *
 * Available since API level 26.
 */
AHardwareBuffer* AHardwareBuffer_fromHardwareBuffer(JNIEnv* env,
        jobject hardwareBufferObj) __INTRODUCED_IN(26);

/**
 * Return a new Java HardwareBuffer object that wraps the passed native
 * AHardwareBuffer object. The Java HardwareBuffer will acquire a reference to
 * the internal buffer and manage its lifetime. For example:
 *
 * <pre><code>
 * AHardwareBuffer* buffer;
 * AHardwareBuffer_allocate(..., &buffer);  // `buffer` has reference count 1
 * jobject java_result = AHardwareBuffer_toHardwareBuffer(buffer);  // `buffer` has reference count 2.
 * AHardwareBuffer_release(buffer); // `buffer` has reference count 1
 * return result;  // The underlying buffer is kept alive by `java_result` and
 *                 // will be set to 0 when it is closed on the Java side with
 *                 // HardwareBuffer::close().
 * </code></pre>
 *
 * Available since API level 26.
 */
jobject AHardwareBuffer_toHardwareBuffer(JNIEnv* env,
        AHardwareBuffer* hardwareBuffer) __INTRODUCED_IN(26);

__END_DECLS

#endif // ANDROID_HARDWARE_BUFFER_JNI_H

/** @} */
