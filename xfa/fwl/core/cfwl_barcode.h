// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef XFA_FWL_CORE_CFWL_BARCODE_H_
#define XFA_FWL_CORE_CFWL_BARCODE_H_

#include "xfa/fwl/core/cfwl_edit.h"
#include "xfa/fwl/core/fwl_error.h"
#include "xfa/fwl/core/ifwl_barcode.h"

class CFWL_Widget;

class CFWL_Barcode : public CFWL_Edit {
 public:
  CFWL_Barcode(const IFWL_App*);
  ~CFWL_Barcode() override;

  void Initialize();

  void SetType(BC_TYPE type);
  bool IsProtectedType();

  void SetCharEncoding(BC_CHAR_ENCODING encoding);
  void SetModuleHeight(int32_t height);
  void SetModuleWidth(int32_t width);
  void SetDataLength(int32_t dataLength);
  void SetCalChecksum(bool calChecksum);
  void SetPrintChecksum(bool printChecksum);
  void SetTextLocation(BC_TEXT_LOC location);
  void SetWideNarrowRatio(int32_t ratio);
  void SetStartChar(FX_CHAR startChar);
  void SetEndChar(FX_CHAR endChar);
  void SetVersion(int32_t version);
  void SetErrorCorrectionLevel(int32_t ecLevel);
  void SetTruncated(bool truncated);
  void ResetBarcodeAttributes();

 protected:
  class CFWL_BarcodeDP : public IFWL_BarcodeDP {
   public:
    CFWL_BarcodeDP();

    // IFWL_DataProvider
    FWL_Error GetCaption(IFWL_Widget* pWidget,
                         CFX_WideString& wsCaption) override;

    // IFWL_BarcodeDP
    BC_CHAR_ENCODING GetCharEncoding() const override;
    int32_t GetModuleHeight() const override;
    int32_t GetModuleWidth() const override;
    int32_t GetDataLength() const override;
    bool GetCalChecksum() const override;
    bool GetPrintChecksum() const override;
    BC_TEXT_LOC GetTextLocation() const override;
    int32_t GetWideNarrowRatio() const override;
    FX_CHAR GetStartChar() const override;
    FX_CHAR GetEndChar() const override;
    int32_t GetVersion() const override;
    int32_t GetErrorCorrectionLevel() const override;
    bool GetTruncated() const override;
    uint32_t GetBarcodeAttributeMask() const override;

    BC_CHAR_ENCODING m_eCharEncoding;
    int32_t m_nModuleHeight;
    int32_t m_nModuleWidth;
    int32_t m_nDataLength;
    bool m_bCalChecksum;
    bool m_bPrintChecksum;
    BC_TEXT_LOC m_eTextLocation;
    int32_t m_nWideNarrowRatio;
    FX_CHAR m_cStartChar;
    FX_CHAR m_cEndChar;
    int32_t m_nVersion;
    int32_t m_nECLevel;
    bool m_bTruncated;
    uint32_t m_dwAttributeMask;
  };

  CFWL_BarcodeDP m_barcodeData;
};

#endif  // XFA_FWL_CORE_CFWL_BARCODE_H_