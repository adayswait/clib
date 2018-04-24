
#pragma once

#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>

/**
 * 返回1970-01-01 00:00:00至今经过的微秒数 
 */
static inline uint64_t get_curr_usec()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}

/**
 * 返回1970-01-01 00:00:00至今经过的秒数 
 */
static inline uint64_t get_curr_sec()
{
    time_t t = time(NULL);
    return t;
}

/**
 * 将当前时间转换为标准时间格式,并储存在std_time中
 * std_time所指向的区域最少24Byte
 */
static inline int get_curr_std_time(char *std_time)
{
    time_t t = time(NULL);
    struct tm *ts = localtime(&t);
    strftime(std_time, 24, "%Y-%m-%d %H:%M:%S", ts);
}

/**
 * 将标准时间格式转换成unix时间戳(秒)
 */

static inline uint64_t std_time_to_sec(const char *std_time)
{
    struct tm ts;
    strptime(std_time, "%Y-%m-%d %H:%M:%S", &ts);
    uint64_t sec = mktime(&ts);
    return sec;
}
