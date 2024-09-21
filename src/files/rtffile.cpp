//////////////////////////////////////////////////////////////////////////////
//
// WordTsar - Wordstar clone for modern systems http://wordtsar.ca
// Copyright (C) 2018 Gerald Brandt
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// Parser based off of https://github.com/kschroeer/rtf-html-java (MIT License)
//
//////////////////////////////////////////////////////////////////////////////

#include <QFile>
#include <QFileInfo>
#include <QProgressDialog>
#include <QApplication>
#include <QTemporaryFile>

#include <cstdlib>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <string>

#include "rtffile.h"
// #include "../include/version.h"
#include "../core/document/document.h"

#include "rtf/write/rtfwriter.h"

using namespace std;

/// @ingroup Editor
/// @{

// extern sExtendedChars gCodePage437[] ;
// extern int gExtendedSize ;
extern sSeqNewColor gBaseWSColors[];

cRTFFile::cRTFFile(cEditorCtrl *editor)
    : cFile(editor)
{
}

cRTFFile::~cRTFFile()
{
}

bool cRTFFile::CheckType(QString filename)
{
    int found = filename.lastIndexOf("."); // Encontra o último ponto
    QString ext = filename.mid(found + 1); // Pega a extensão a partir do último ponto

    ext = ext.toLower(); // Converte para minúsculas

    return (ext == "rtf");
}

bool cRTFFile::LoadFile(QString filename)
{
    bool retval = false;

    QString rtf;

    FILE *fp;

    fp = fopen(filename.toStdString().c_str(), "r"); // Converte QString para std::string antes de abrir o arquivo
    if (!fp)
    {
        return false;
    }
    else
    {
        cRTFParser parser(fp, &mEditor->mDocument, this);

        fclose(fp);

        retval = true;
        //        QApplication::restoreOverrideCursor();
    }

    return retval;
}

bool cRTFFile::SaveFile(QString filename, POSITION_T length)
{
    UNUSED_ARGUMENT(length);

    bool retval = false;

    std::string stdFilename = filename.toStdString();

    cRTFWriter write(mEditor);
    retval = write.Start(stdFilename);

    return retval;
}

bool cRTFFile::CanLoad(void)
{
    return true;
}

bool cRTFFile::CanSave(void)
{
    return true;
}

QString cRTFFile::GetExtensions(void)
{
    return "RTF Files (*.rtf *.RTF)";
}

/// @}
