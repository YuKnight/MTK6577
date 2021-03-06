/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 * 
 * MediaTek Inc. (C) 2010. All rights reserved.
 * 
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */

///////////////////////////////////////////////////////////////////////////////
// No Warranty
// Except as may be otherwise agreed to in writing, no warranties of any
// kind, whether express or implied, are given by MTK with respect to any MTK
// Deliverables or any use thereof, and MTK Deliverables are provided on an
// "AS IS" basis.  MTK hereby expressly disclaims all such warranties,
// including any implied warranties of merchantability, non-infringement and
// fitness for a particular purpose and any warranties arising out of course
// of performance, course of dealing or usage of trade.  Parties further
// acknowledge that Company may, either presently and/or in the future,
// instruct MTK to assist it in the development and the implementation, in
// accordance with Company's designs, of certain softwares relating to
// Company's product(s) (the "Services").  Except as may be otherwise agreed
// to in writing, no warranties of any kind, whether express or implied, are
// given by MTK with respect to the Services provided, and the Services are
// provided on an "AS IS" basis.  Company further acknowledges that the
// Services may contain errors, that testing is important and Company is
// solely responsible for fully testing the Services and/or derivatives
// thereof before they are used, sublicensed or distributed.  Should there be
// any third party action brought against MTK, arising out of or relating to
// the Services, Company agree to fully indemnify and hold MTK harmless.
// If the parties mutually agree to enter into or continue a business
// relationship or other arrangement, the terms and conditions set forth
// hereunder shall remain effective and, unless explicitly stated otherwise,
// shall prevail in the event of a conflict in the terms in any agreements
// entered into between the parties.
////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2008, MediaTek Inc.
// All rights reserved.
//
// Unauthorized use, practice, perform, copy, distribution, reproduction,
// or disclosure of this information in whole or in part is prohibited.
////////////////////////////////////////////////////////////////////////////////
// AcdkSurfaceView.h  $Revision$
////////////////////////////////////////////////////////////////////////////////

//! \file  AcdkSurfaceView.h 
//! \brief

#ifndef _ACDKSURFACEVIEW_H_
#define _ACDKSURFACEVIEW_H_

#define OVERLAY_BUFFER_CNT 5

namespace NSACDK 
{

typedef enum {
    ACDKSURFACE_NO_ERROR         = 0,            ///< The function work successfully
    ACDKSURFACE_UNKNOWN_ERROR    = 0x80000000,   ///< Unknown error    
    ACDKSURFACE_INVALID_DRIVER   = 0x80000001,
    ACDKSURFACE_API_FAIL         = 0x80000002,
    ACDKSURFACE_INVALID_PARA     = 0x80000004, 
} ACDKSURFACE_ERROR_ENUM;

/*******************************************************************************
 * 
 *******************************************************************************/	
typedef struct overlayBufInfo_t {
    MUINT32 startx; 
    MUINT32 starty; 
    MUINT32 width; 
    MUINT32 height; 
    MUINT32 virtAddr; 
    MUINT32 phyAddr;
} overlayBufInfo; 


/*******************************************************************************
* ! \class AcdkSurfaceView 
*******************************************************************************/
class AcdkSurfaceView 
{	
public:      
   /*******************************************************************************
    * 
    *******************************************************************************/	
    static AcdkSurfaceView* createInstance(); 
    
    virtual void  destroyInstance() = 0;
    
    virtual MINT32 init() = 0; 
    
    virtual MINT32 uninit() = 0;     

    virtual MINT32 setOverlayBuf(
        MUINT32 const layerNo, 
        MUINT8 const *pSrcIn, 
        MUINT32 const srcFmt,  
        MUINT32 const srcW, 
        MUINT32 const srcH, 
        MUINT32 const orientation, 
        MUINT32 const hFlip, 
        MUINT32 const vFlip           
    ) = 0;
    
    virtual MINT32 getSurfaceInfo(
            MUINT32 &width,
            MUINT32 &height, 
            MUINT32 &orientation
    ) = 0;
         
    virtual MINT32 setOverlayInfo(
            MUINT32 const layerNo, 
            MUINT32 const startx, 
            MUINT32 const starty, 
            MUINT32 const width, 
            MUINT32 const height, 
            MUINT32 const phyAddr, 
            MUINT32 const virtAddr,
            MUINT32 const orientation          
    ) = 0; 
    
                                    
#if defined (MTK_M4U_SUPPORT)
    virtual MINT32 registerBuffer(MUINT32 virtAddr, MUINT32 size); 
    virtual MINT32 unRegisterBuffer(MUINT32 virtAddr); 
#endif    
    
    virtual MINT32 resetLayer( 
            MUINT32 const layerNo
    ) = 0; 
    
    virtual MINT32 refresh() = 0; 
        
   /*******************************************************************************
    * 
    *******************************************************************************/	
    virtual MINT32 getNumLayer(MUINT32 &numLayer) = 0;  
    //
    virtual MINT32 getFBNo() = 0; 
                              
protected:
    AcdkSurfaceView() {}; 
    virtual ~AcdkSurfaceView() {};     
};

}
#endif //end AcdkSurfaceView.h 

