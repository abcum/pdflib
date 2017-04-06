// Copyright © 2016 Abcum Ltd
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this info except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// +build cgo

package pdflib

// #include <stdio.h>
// #include <stdlib.h>
// #include "pdflib.h"
import "C"

type Instance struct {
	val *C.PDF
}

func New() *Instance {
	return &Instance{val: C.PDF_new()}
}

// AddNamedDest
func (i *Instance) AddNamedDest(name, options string) {}

// AddPathPoint
func (i *Instance) AddPathPoint(path int, x, y float64, kind, options string) {}

// AddTableCell
func (i *Instance) AddTableCell(table, col, row int, text, options string) {}

// AddTextflow
func (i *Instance) AddTextflow(textflow int, text, options string) {}

// AddThumbnail
func (i *Instance) AddThumbnail(image int) {}

// Align
func (i *Instance) Align(x, y float64) {}

// Arc
func (i *Instance) Arc(x, y, r, alpha, beta float64) {}

// Arcn
func (i *Instance) Arcn(x, y, r, alpha, beta float64) {}

// BeginDocument
func (i *Instance) BeginDocument(filename, options string) {}

// BeginDocumentCallback
func (i *Instance) BeginDocumentCallback() {} // FIXME

// BeginFont
func (i *Instance) BeginFont(fontname string, a, b, c, d, e, f float64, options string) {}

// BeginGlyph
func (i *Instance) BeginGlyph(glyphname string, wx, llx, lly, urx, ury float64) {}

// BeginPageExt adds a new page to the document, and specify various options.
func (i *Instance) BeginPageExt(w, h float64, options string) {}

// BeginTemplate
func (i *Instance) BeginTemplate(w, h float64) {}

// Circle
func (i *Instance) Circle(x, y, r float64) {}

// CircularArc
func (i *Instance) CircularArc(x1, y1, x2, y2 float64) {}

// Clip
func (i *Instance) Clip() {}

// CloseFont closes an open font handle which has not yet been used in the document.
func (i *Instance) CloseFont(font int) {}

// CloseImage closes an image
func (i *Instance) CloseImage(image int) {}

// ClosePdiDocument
func (i *Instance) ClosePdiDocument(doc int) {}

// ClosePdiPage
func (i *Instance) ClosePdiPage(page int) {}

// ClosePath
func (i *Instance) ClosePath() {}

// ClosePathFillStroke
func (i *Instance) ClosePathFillStroke() {}

// Concat
func (i *Instance) Concat(a, b, c, d, e, f float64) {}

// ContinueText
func (i *Instance) ContinueText(text string) {}

// Create3dView
func (i *Instance) Create3dView(username, options string) {}

// CreateAction
func (i *Instance) CreateAction(kind, options string) {}

// CreateAnnotation
func (i *Instance) CreateAnnotation(llx, llr, urx, ury float64, kind, options string) {}

// CreateBookmark
func (i *Instance) CreateBookmark(text, options string) {}

// CreateField
func (i *Instance) CreateField(llx, lly, urx, ury float64, name, kind, options string) {}

// CreateFieldgroup
func (i *Instance) CreateFieldgroup(name, options string) {}

// CreateGstate
func (i *Instance) CreateGstate(options string) {}

// CreatePvf
func (i *Instance) CreatePvf(filename string, data []byte, options string) {}

// CreateTextflow
func (i *Instance) CreateTextflow(text, options string) {}

// CurveTo
func (i *Instance) CurveTo(x1, y1, x2, y2, x3, y3 float64) {}

// DefineLayer
func (i *Instance) DefineLayer(name, options string) {}

// Delete
func (i *Instance) Delete() {}

// DeletePath
func (i *Instance) DeletePath(path int) {}

// DeletePvf
func (i *Instance) DeletePvf(filename string) {}

// DeleteTable
func (i *Instance) DeleteTable(table int, options string) {}

// DeleteTextflow
func (i *Instance) DeleteTextflow(textflow int) {}

// DrawPath
func (i *Instance) DrawPath(path int, x, y float64, options string) {}

// Ellipse
func (i *Instance) Ellipse(x, y, rx, ry float64) {}

// EndDocument
func (i *Instance) EndDocument(options string) {}

// EndFont
func (i *Instance) EndFont() {}

// EndGlyph
func (i *Instance) EndGlyph() {}

// EndItem
func (i *Instance) EndItem(id int) {}

// EndLayer
func (i *Instance) EndLayer() {}

// EndMc
func (i *Instance) EndMc() {}

// EndPageExt
func (i *Instance) EndPageExt() {}

// EndPattern
func (i *Instance) EndPattern() {}

// EndTemplateExt
func (i *Instance) EndTemplateExt(w, h float64) {}

// EndPath
func (i *Instance) EndPath() {}

// Fill
func (i *Instance) Fill() {}

// FillImageblock
func (i *Instance) FillImageblock(page int, blockname string, image int, options string) {}

// FillPdfblock
func (i *Instance) FillPdfblock(page int, blockname string, document int, options string) {}

// FillTextblock
func (i *Instance) FillTextblock(page int, blockname, text, options string) {}

// FitImage
func (i *Instance) FitImage(image int, x, y float64, options string) {}

// FitPdiPage
func (i *Instance) FitPdiPage(page int, x, y float64, options string) {}

// FitTable
func (i *Instance) FitTable(table int, llx, lly, urx, ury float64, options string) {}

// FitTextflow
func (i *Instance) FitTextflow(textflow int, llx, lly, urx, ury, options string) {}

// FitTextline
func (i *Instance) FitTextline(text string, x, y, float64, options string) {}

// GetBuffer
func (i *Instance) GetBuffer() {}

// GetParameter
func (i *Instance) GetParameter(key string, modifier float64) {}

// GetValue
func (i *Instance) GetValue(key string, modifier float64) {}

// InfoFont
func (i *Instance) InfoFont(font int, keyword, options string) {}

// InfoImage
func (i *Instance) InfoImage(image int, keyword, options string) {}

// InfoMatchbox
func (i *Instance) InfoMatchbox(boxname string, num int, keyword string) {}

// InfoPath
func (i *Instance) InfoPath(path int, keyword, options string) {}

// InfoPdiPage
func (i *Instance) InfoPdiPage(page int, keyword, options string) {}

// InfoTable
func (i *Instance) InfoTable(table int, keyword string) {}

// InfoTextflow
func (i *Instance) InfoTextflow(textflow int, keyword string) {}

// InfoTextline
func (i *Instance) InfoTextline(text, keyword, options string) {}

// InitGraphics
func (i *Instance) InitGraphics() {}

// LineTo
func (i *Instance) LineTo(x, y float64) {}

// Load3dData
func (i *Instance) Load3dData(filename, options string) {}

// LoadFont
func (i *Instance) LoadFont(fontname, encoding, options string) {}

// LoadIccProfile
func (i *Instance) LoadIccProfile(profilename, options string) {}

// LoadImage
func (i *Instance) LoadImage(imagetype, filename, options string) {}

// MakeSpotColor
func (i *Instance) MakeSpotColor(spotname string) {}

// McPoint
func (i *Instance) McPoint(tag, options string) {}

// MoveTo
func (i *Instance) MoveTo(x, y float64) {}

// OpenPdiDocument
func (i *Instance) OpenPdiDocument(filename, options string) {}

// OpenPdiCallback
func (i *Instance) OpenPdiCallback() {} // FIXME

// OpenPdiPage
func (i *Instance) OpenPdiPage(doc, page int, options string) {}

// PcosGetNumber
func (i *Instance) PcosGetNumber(doc int, path string) {}

// PcosGetString
func (i *Instance) PcosGetString(doc int, path string) {}

// PcosGetStream
func (i *Instance) PcosGetStream(doc int, options, path string) {}

// ProcessPdi
func (i *Instance) ProcessPdi(doc, page int, options string) {}

// RCurveTo
func (i *Instance) RCurveTo(x1, y1, x2, y2, x3, y3 float64) {}

// Rect
func (i *Instance) Rect(x, y, w, h float64) {}

// Restore
func (i *Instance) Restore() {}

// ResumePage
func (i *Instance) ResumePage(options string) {}

// Rotate
func (i *Instance) Rotate(phi float64) {}

// Save
func (i *Instance) Save() {}

// Scale
func (i *Instance) Scale(sx, sy float64) {}

// SetGstate
func (i *Instance) SetGstate(gstate int) {}

// SetInfo
func (i *Instance) SetInfo(key, value string) {}

// SetLayerDependency
func (i *Instance) SetLayerDependency(kind, options string) {}

// SetOption
func (i *Instance) SetOption(options string) {}

// SetParameter
func (i *Instance) SetParameter(key, value string) {}

// SetTextPos
func (i *Instance) SetTextPos(x, y float64) {}

// SetValue
func (i *Instance) SetValue(x, y float64) {}

// SetColor
func (i *Instance) SetColor(fstype, colorspace string, c1, c2, c3, c4 float64) {}

// SetDash
func (i *Instance) SetDash(b, w float64) {}

// SetDashPattern
func (i *Instance) SetDashPattern(options string) {}

// SetFlat
func (i *Instance) SetFlat(flatness float64) {}

// SetFont
func (i *Instance) SetFont(font int, fontsize float64) {}

// SetGray
func (i *Instance) SetGray(gray float64) {}

// SetGrayFill
func (i *Instance) SetGrayFill(gray float64) {}

// SetGrayStroke
func (i *Instance) SetGrayStroke(gray float64) {}

// SetLinecap
func (i *Instance) SetLinecap(linecap int) {}

// SetLinejoin
func (i *Instance) SetLinejoin(linejoin int) {}

// SetLinewidth
func (i *Instance) SetLinewidth(width float64) {}

// SetMatrix
func (i *Instance) SetMatrix(a, b, c, d, e, f float64) {}

// SetMatrix
func (i *Instance) SetMiterLimit(miter float64) {}

// Shading
func (i *Instance) Shading(shtype string, x0, y0, x1, y1, c1, c2, c3, c4 float64, options string) {}

// ShadingPattern
func (i *Instance) ShadingPattern(shading int, options string) {}

// Shfill
func (i *Instance) Shfill(shading int) {}

// Show
func (i *Instance) Show(text string) {}

// ShowXY
func (i *Instance) ShowXY(text string, x, y float64) {}

// Skew
func (i *Instance) Skew(alpha, beta float64) {}

// StringWidth
func (i *Instance) StringWidth(text string, font int, fontsize float64) {}

// Stroke
func (i *Instance) Stroke() {}

// SuspendPage
func (i *Instance) SuspendPage(options string) {}

// Translate
func (i *Instance) Translate(tx, ty float64) {}
