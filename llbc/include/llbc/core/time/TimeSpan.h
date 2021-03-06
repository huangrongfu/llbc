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

#ifndef __LLBC_CORE_TIME_TIMESPAN_H__
#define __LLBC_CORE_TIME_TIMESPAN_H__

#include "llbc/common/Common.h"

__LLBC_NS_BEGIN

/**
 * Previous declare Time & TimeSpan class.
 */
class LLBC_Time;
class LLBC_TimeSpan;

__LLBC_NS_END

/**
 * TimeSpan class stream output operators previous declare.
 */
LLBC_EXTERN std::ostream & operator <<(std::ostream &stream, const LLBC_NS LLBC_TimeSpan &span);

__LLBC_NS_BEGIN

/**
 * \brief Time span class encapsulation.
 */
class LLBC_EXPORT LLBC_TimeSpan
{
public:
    /**
     * Default constructor, construct zero span object.
     */
    LLBC_TimeSpan();

    /**
     * Construct by span, in seconds.
     * @param[in] seconds      - the span seconds part.
     * @param[in] milliSeconds - the span milli-seconds part.
     * @param[in] microSeconds - the span micro-seconds part.
     */
    explicit LLBC_TimeSpan(int seconds, int milliSeconds = 0, int microSeconds = 0);

    /**
     * Construct by span string representation(fmt: 00:00:00.xxxxxx).
     * @param[in] span - the span value string representation, fmt: 00:00:00.xxxxx, the micro-seconds is optional.
     */
    LLBC_TimeSpan(const LLBC_String &span);

    /**
     * Copy constructor.
     */
    LLBC_TimeSpan(const LLBC_TimeSpan &span);

    /**
     * Time span parts constructor.
     * @param[in] days         - the days part.
     * @param[in] hours        - the hours part.
     * @param[in] minutes      - the minutes part.
     * @param[in] seconds      - the seconds part.
     * @param[in] milliSeconds - the milli-seconds part, default is 0.
     * @param[in] microSeconds - the micro-seconds part, default is 0.
     */
    LLBC_TimeSpan(int days, int hours, int minutes, int seconds, int milliSeconds = 0, int microSeconds = 0);

    /**
     * Destructor.
     */
    ~LLBC_TimeSpan();

public:
    /**
     * Get days/hours/minutes/seconds/milli-seconds/micro-seconds.
     * @return int - the time span parts value.
     */
    int GetDays() const;
    int GetHours() const;
    int GetMinutes() const;
    int GetSeconds() const;
    int GetMilliSeconds() const;
    int GetMicroSeconds() const;

    int GetTotalDays() const;
    int GetTotalHours() const;
    int GetTotalMinutes() const;
    int GetTotalSeconds() const;
    sint64 GetTotalMilliSeconds() const;
    const sint64 &GetTotalMicroSeconds() const;

    LLBC_TimeSpan operator +(const LLBC_TimeSpan &span) const;
    LLBC_TimeSpan operator -(const LLBC_TimeSpan &span) const;

    LLBC_TimeSpan &operator +=(const LLBC_TimeSpan &span);
    LLBC_TimeSpan &operator -=(const LLBC_TimeSpan &span);

    bool operator ==(const LLBC_TimeSpan &span) const;
    bool operator !=(const LLBC_TimeSpan &span) const;
    bool operator <(const LLBC_TimeSpan &span)const;
    bool operator >(const LLBC_TimeSpan &span) const;
    bool operator <=(const LLBC_TimeSpan &span) const;
    bool operator >=(const LLBC_TimeSpan &span) const;

    LLBC_TimeSpan &operator =(const LLBC_TimeSpan &span);

public:
    /**
     * Get the timespan object string representation.
     * @return LLBC_String - the object string representation.
     */
    LLBC_String ToString() const;

public:
    /**
     * Stream output operator support.
     */
    friend std::ostream & ::operator <<(std::ostream &o, const LLBC_TimeSpan &s);

public:
    /**
     * Serialize&DeSerialize support.
     */
    void Serialize(LLBC_Stream &stream) const;
    bool DeSerialize(LLBC_Stream &stream);

    void SerializeEx(LLBC_Stream &stream) const;
    bool DeSerializeEx(LLBC_Stream &stream);

private:
    // Declare friend class:LLBC_Time.
    // Access members:
    // - LLBC_TimeSpan::LLBC_TimeSpan(const sint64 &span)
    friend class LLBC_Time;

private:
    LLBC_TimeSpan(const sint64 &span);

private:
    sint64 _span;
};

__LLBC_NS_END

#include "llbc/core/time/TimeSpanImpl.h"

#endif // !__LLBC_CORE_TIME_TIMESPAN_H__
