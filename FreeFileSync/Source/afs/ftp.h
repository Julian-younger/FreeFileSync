// *****************************************************************************
// * This file is part of the FreeFileSync project. It is distributed under    *
// * GNU General Public License: https://www.gnu.org/licenses/gpl-3.0          *
// * Copyright (C) Zenju (zenju AT freefilesync DOT org) - All Rights Reserved *
// *****************************************************************************

#ifndef FTP_H_745895742383425326568678
#define FTP_H_745895742383425326568678

#include "abstract.h"


namespace fff
{
bool  acceptsItemPathPhraseFtp(const Zstring& itemPathPhrase); //noexcept
AbstractPath createItemPathFtp(const Zstring& itemPathPhrase); //noexcept

void ftpInit();
void ftpTeardown();

//-------------------------------------------------------

struct FtpLoginInfo
{
    Zstring server;
    int port = 0; // > 0 if set
    Zstring username;
    Zstring password;
    bool useTls = false;

    //other settings not specific to FTP session:
    int timeoutSec = 15;
};
AfsDevice condenseToFtpDevice(const FtpLoginInfo& login); //noexcept; potentially messy user input
FtpLoginInfo extractFtpLogin(const AfsDevice& afsDevice); //noexcept

AfsPath getFtpHomePath(const FtpLoginInfo& login); //throw FileError
}

#endif //FTP_H_745895742383425326568678
