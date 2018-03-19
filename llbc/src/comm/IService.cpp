// The MIT License (MIT)

// Copyright (c) 2013 lailongwei<lailongwei@126.com>
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy of 
// this software and associated documentation files (the "Software"), to deal in 
// the Software without restriction, including without limitation the rights to 
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of 
// the Software, and to permit persons to whom the Software is furnished to do so, 
// subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all 
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS 
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR 
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER 
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN 
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


#include "llbc/common/Export.h"
#include "llbc/common/BeforeIncl.h"

#include "llbc/comm/Service.h"

namespace
{
    typedef LLBC_NS LLBC_IService This;
}

__LLBC_NS_BEGIN

This *LLBC_IService::Create(Type type, const LLBC_String &name, LLBC_IProtocolFactory *protoFactory)
{
    return LLBC_New3(LLBC_Service, type, name, protoFactory);
}

#if LLBC_CFG_COMM_ENABLE_SAMPLER_SUPPORT
int LLBC_IService::PushSamplerMsg(LLBC_MessageBlock *block)
{
    _samplerMsgQueue.PushBack(block);
    return LLBC_OK;
}

int LLBC_IService::TryPopSamplerMsg(LLBC_MessageBlock *&block)
{
    if (_samplerMsgQueue.TryPopFront(block))
        return LLBC_OK;

    return LLBC_FAILED;
}
#endif

__LLBC_NS_END

#include "llbc/common/AfterIncl.h"
