/** @file
 *
 * This file implements error class and relevant operations
 */

#include <msgmap_error.h>

const char *msgmap_error_t::what() const noexcept
{
    switch (error_code)
    {
        case STMPFS_EXT_LIB_ERR:
            return MSGMAP_PREFIX "External library error";

        default:
            return MSGMAP_PREFIX "Unknown";
    }
}
