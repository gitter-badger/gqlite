#pragma once

#define GQL_DEBUG(info) printf("DEBUG: %s\n", info)

enum ErrorCode {
  ECode_Success = 0,
  ECODE_NULL_PTR,
  ECode_No_Memory,
  ECode_DB_Create_Fail
};