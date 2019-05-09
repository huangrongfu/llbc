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

#ifndef __LLBC_CORE_LOG_LOG_JSONMSG_H__
#define __LLBC_CORE_LOG_LOG_JSONMSG_H__

#include "llbc/common/Common.h"
#include "llbc/core/rapidjson/json.h"

__LLBC_NS_BEGIN

/**
 * Pre-declare some classes.
 */
class LLBC_Logger;

/**
 * \brief The json log msg class encapsulation.
 */
class LLBC_EXPORT LLBC_LogJsonMsg
{
public:
    explicit LLBC_LogJsonMsg(bool loggerInited, LLBC_Logger *logger, const char* tag, int lv);
    ~LLBC_LogJsonMsg();

public:
    /**
    * Add json styled message
    */
    LLBC_LogJsonMsg &Add(const char *key, const char *value);
    template <typename T>
    LLBC_LogJsonMsg &Add(const char *key, const T &value);

    /**
    * Output json styled message
    */
    void Finish(const char *fmt, ...);

private:
    /**
    * When logger component not initialize, will use this function to output message.
    */
    static void UnInitOutput(FILE *to, const char *msg);

private:
    bool _loggerInited;
    LLBC_Logger *_logger;
    const char *_tag;
    int _lv;

    LLBC_Json::Document _doc;
};

__LLBC_NS_END

#include "llbc/core/log/LogJsonMsgImpl.h"

#endif // !__LLBC_CORE_LOG_LOG_JSONMSG_H__