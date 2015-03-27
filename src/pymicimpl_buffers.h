/* Copyright (c) 2014-2015, Intel Corporation All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are 
 * met: 
 *
 * 1. Redistributions of source code must retain the above copyright 
 * notice, this list of conditions and the following disclaimer. 
 * 
 * 2. Redistributions in binary form must reproduce the above copyright 
 * notice, this list of conditions and the following disclaimer in the 
 * documentation and/or other materials provided with the distribution. 
 *
 * 3. Neither the name of the copyright holder nor the names of its 
 * contributors may be used to endorse or promote products derived from 
 * this software without specific prior written permission. 
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS 
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED 
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A 
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED 
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */
 
#ifndef PYMIC_BUFFERS_H
#define PYMIC_BUFFERS_H

#include <cstddef>
#include <stdint.h>

namespace pymic {

uintptr_t buffer_lookup_device_ptr(int, void*);
uintptr_t buffer_lookup_device_ptr(int, uintptr_t);

unsigned char * buffer_allocate(int, void *, size_t, size_t);
void buffer_release(int, void *, unsigned char *);
void buffer_copy_to_target(int, void *, 
                           unsigned char *, unsigned char *, 
                           size_t, size_t, size_t);
void buffer_copy_to_host(int, void *, 
                         unsigned char *, unsigned char *, 
                         size_t, size_t, size_t);
void buffer_copy_on_device(int, void *, 
                           unsigned char *, unsigned char *, 
                           size_t, size_t, size_t);
uintptr_t buffer_translate_pointer(unsigned char *);

struct buffer_descriptor {
    uintptr_t pointer;
    size_t size;
};

} // namespace pymic

#endif 
