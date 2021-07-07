#pragma once

#define GQL_DEBUG(info) printf("DEBUG: %s\n", info)

enum ErrorCode {
  ECode_Success = 0,
  ECode_No_Memory,
  ECode_DB_Create_Fail
};