#include "../redismodule.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* A sample movable keys command that returns a list of all
 * arguments that follow a KEY argument, i.e.
 */
int ping_command(RedisModuleCtx *ctx, RedisModuleString **argv, int argc)
{
    REDISMODULE_NOT_USED(argv);
    REDISMODULE_NOT_USED(argc);

    RedisModuleString *s = RedisModule_CreateString(ctx,"are you ok ?",12);
    //RedisModule_StringAppendBuffer(ctx,s,"bar",3);
    RedisModule_ReplyWithString(ctx,s);
    RedisModule_FreeString(ctx,s);
    return REDISMODULE_OK;
}

int RedisModule_OnLoad(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {
    REDISMODULE_NOT_USED(argv);
    REDISMODULE_NOT_USED(argc);

    if (RedisModule_Init(ctx, "robin", 1, REDISMODULE_APIVER_1)
        == REDISMODULE_ERR)
        return REDISMODULE_ERR;

    if (RedisModule_CreateCommand(ctx, "robin.ping",
                                  ping_command, "write deny-oom", 1, 1, 1) == REDISMODULE_ERR)
        return REDISMODULE_ERR;
}