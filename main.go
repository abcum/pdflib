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

//go:build cgo
// +build cgo

package pdflib

// #include <stdio.h>
// #include <stdlib.h>
// #include "golang.h"
// #include "pdflib.h"
import "C"

import (
	"errors"
	"unsafe"
)

// PDFlib represents a PDFlib instance.
type PDFlib struct {
	val *C.PDF
}

// New creates a new PDFlb instance.
func New() *PDFlib {
	pdflib := &PDFlib{val: C.PDF_new()}
	pdflib.SetParameter("errorpolicy", "exception")
	return pdflib
}

func (p *PDFlib) catch() error {
	if num := C._PDF_get_errnum(p.val); num > 0 {
		return errors.New(C.GoString(C._PDF_get_errmsg(p.val)))
	}
	return nil
}

// AddNamedDest ...
func (p *PDFlib) AddNamedDest(name, options string) error {
	cName := C.CString(name)
	cOptions := C.CString(options)
	C._PDF_add_nameddest(p.val, cName, 0, cOptions)
	C.free(unsafe.Pointer(cOptions))
	C.free(unsafe.Pointer(cName))
	return p.catch()
}

// AddPathPoint ...
func (p *PDFlib) AddPathPoint(path int, x, y float64, kind, options string) (int, error) {
	cKind := C.CString(kind)
	cOptions := C.CString(options)
	ret := int(C._PDF_add_path_point(p.val, C.int(path), C.double(x), C.double(y), cKind, cOptions))
	C.free(unsafe.Pointer(cOptions))
	C.free(unsafe.Pointer(cKind))
	return ret, p.catch()
}

// AddTableCell ...
func (p *PDFlib) AddTableCell(table, col, row int, text, options string) (int, error) {
	cText := C.CString(text)
	cOptions := C.CString(options)
	ret := int(C._PDF_add_table_cell(p.val, C.int(table), C.int(col), C.int(row), cText, 0, cOptions))
	C.free(unsafe.Pointer(cOptions))
	C.free(unsafe.Pointer(cText))
	return ret, p.catch()
}

// AddTextflow ...
func (p *PDFlib) AddTextflow(textflow int, text, options string) (int, error) {
	cText := C.CString(text)
	cOptions := C.CString(options)
	ret := int(C._PDF_add_textflow(p.val, C.int(textflow), cText, 0, cOptions))
	C.free(unsafe.Pointer(cOptions))
	C.free(unsafe.Pointer(cText))
	return ret, p.catch()
}

// AddThumbnail ...
func (p *PDFlib) AddThumbnail(image int) error {
	C._PDF_add_thumbnail(p.val, C.int(image))
	return p.catch()
}

// Align ...
func (p *PDFlib) Align(x, y float64) error {
	C._PDF_align(p.val, C.double(x), C.double(y))
	return p.catch()
}

// Arc ...
func (p *PDFlib) Arc(x, y, r, alpha, beta float64) error {
	C._PDF_arc(p.val, C.double(x), C.double(y), C.double(r), C.double(alpha), C.double(beta))
	return p.catch()
}

// Arcn ...
func (p *PDFlib) Arcn(x, y, r, alpha, beta float64) error {
	C._PDF_arcn(p.val, C.double(x), C.double(y), C.double(r), C.double(alpha), C.double(beta))
	return p.catch()
}

// BeginDocument ...
func (p *PDFlib) BeginDocument(filename, options string) (int, error) {
	cOptions := C.CString(options)
	cFilename := C.CString(filename)
	ret := int(C._PDF_begin_document(p.val, cFilename, 0, cOptions))
	C.free(unsafe.Pointer(cFilename))
	C.free(unsafe.Pointer(cOptions))
	return ret, p.catch()
}

// BeginFont ...
func (p *PDFlib) BeginFont(fontname string, a, b, c, d, e, f float64, options string) error {
	cOptions := C.CString(options)
	cFontname := C.CString(fontname)
	C._PDF_begin_font(p.val, cFontname, 0, C.double(a), C.double(b), C.double(c), C.double(d), C.double(e), C.double(f), cOptions)
	C.free(unsafe.Pointer(cFontname))
	C.free(unsafe.Pointer(cOptions))
	return p.catch()
}

// BeginGlyph ...
func (p *PDFlib) BeginGlyph(glyphname string, wx, llx, lly, urx, ury float64) error {
	cGlyphname := C.CString(glyphname)
	C._PDF_begin_glyph(p.val, cGlyphname, C.double(wx), C.double(llx), C.double(lly), C.double(urx), C.double(ury))
	C.free(unsafe.Pointer(cGlyphname))
	return p.catch()
}

// BeginItem ..
func (p *PDFlib) BeginItem(tag, options string) (int, error) {
	cOptions := C.CString(options)
	ret := int(C._PDF_begin_item(p.val, C.CString(tag), cOptions))
	C.free(unsafe.Pointer(cOptions))
	return ret, p.catch()
}

// BeginLayer ..
func (p *PDFlib) BeginLayer(layer int) error {
	C._PDF_begin_layer(p.val, C.int(layer))
	return p.catch()
}

// BeginPageExt adds a new page to the document, and specify various options.
func (p *PDFlib) BeginPageExt(w, h float64, options string) error {
	cOptions := C.CString(options)
	C._PDF_begin_page_ext(p.val, C.double(w), C.double(h), cOptions)
	C.free(unsafe.Pointer(cOptions))
	return p.catch()
}

// BeginPattern ..
func (p *PDFlib) BeginPattern(w, h, xstep, ystep float64, painttype int) (int, error) {
	ret := int(C._PDF_begin_pattern(p.val, C.double(w), C.double(h), C.double(xstep), C.double(ystep), C.int(painttype)))
	return ret, p.catch()
}

// BeginTemplate ...
func (p *PDFlib) BeginTemplate(w, h float64, options string) (int, error) {
	cOptions := C.CString(options)
	ret := int(C._PDF_begin_template_ext(p.val, C.double(w), C.double(h), cOptions))
	C.free(unsafe.Pointer(cOptions))
	return ret, p.catch()
}

// Circle ...
func (p *PDFlib) Circle(x, y, r float64) error {
	C._PDF_circle(p.val, C.double(x), C.double(y), C.double(r))
	return p.catch()
}

// CircularArc ...
func (p *PDFlib) CircularArc(x1, y1, x2, y2 float64) error {
	C._PDF_circular_arc(p.val, C.double(x1), C.double(y1), C.double(x2), C.double(y2))
	return p.catch()
}

// Clip ...
func (p *PDFlib) Clip() error {
	C._PDF_clip(p.val)
	return p.catch()
}

// CloseFont closes an open font handle which has not yet been used in the document.
func (p *PDFlib) CloseFont(font int) error {
	C._PDF_close_font(p.val, C.int(font))
	return p.catch()
}

// CloseGraphics closes vector graphics.
func (p *PDFlib) CloseGraphics(graphics int) error {
	C._PDF_close_graphics(p.val, C.int(graphics))
	return p.catch()
}

// CloseImage closes an image ...
func (p *PDFlib) CloseImage(image int) error {
	C._PDF_close_image(p.val, C.int(image))
	return p.catch()
}

// ClosePdiDocument ...
func (p *PDFlib) ClosePdiDocument(doc int) error {
	C._PDF_close_pdi_document(p.val, C.int(doc))
	return p.catch()
}

// ClosePdiPage ...
func (p *PDFlib) ClosePdiPage(page int) error {
	C._PDF_close_pdi_page(p.val, C.int(page))
	return p.catch()
}

// ClosePath ...
func (p *PDFlib) ClosePath() error {
	C._PDF_closepath(p.val)
	return p.catch()
}

// ClosePathFillStroke ...
func (p *PDFlib) ClosePathFillStroke() error {
	C._PDF_closepath_fill_stroke(p.val)
	return p.catch()
}

// ClosePathStroke ...
func (p *PDFlib) ClosePathStroke() error {
	C._PDF_closepath_stroke(p.val)
	return p.catch()
}

// Concat ...
func (p *PDFlib) Concat(a, b, c, d, e, f float64) error {
	C._PDF_concat(p.val, C.double(a), C.double(b), C.double(c), C.double(d), C.double(e), C.double(f))
	return p.catch()
}

// ContinueText ...
func (p *PDFlib) ContinueText(text string) error {
	cText := C.CString(text)
	C._PDF_continue_text(p.val, cText)
	C.free(unsafe.Pointer(cText))
	return p.catch()
}

// Create3dView ...
func (p *PDFlib) Create3dView(username, options string) error {
	cUsername := C.CString(username)
	cOptions := C.CString(options)
	C._PDF_create_3dview(p.val, cUsername, 0, cOptions)
	C.free(unsafe.Pointer(cOptions))
	C.free(unsafe.Pointer(cUsername))
	return p.catch()
}

// CreateAction ...
func (p *PDFlib) CreateAction(kind, options string) (int, error) {
	cKind := C.CString(kind)
	cOptions := C.CString(options)
	ret := int(C._PDF_create_action(p.val, cKind, cOptions))
	C.free(unsafe.Pointer(cOptions))
	C.free(unsafe.Pointer(cKind))
	return ret, p.catch()
}

// CreateAnnotation ...
func (p *PDFlib) CreateAnnotation(llx, llr, urx, ury float64, kind, options string) error {
	cKind := C.CString(kind)
	cOptions := C.CString(options)
	C._PDF_create_annotation(p.val, C.double(llx), C.double(llr), C.double(urx), C.double(ury), cKind, cOptions)
	C.free(unsafe.Pointer(cOptions))
	C.free(unsafe.Pointer(cKind))
	return p.catch()
}

// CreateBookmark ...
func (p *PDFlib) CreateBookmark(text, options string) (int, error) {
	cText := C.CString(text)
	cOptions := C.CString(options)
	ret := int(C._PDF_create_bookmark(p.val, cText, 0, cOptions))
	C.free(unsafe.Pointer(cOptions))
	C.free(unsafe.Pointer(cText))
	return ret, p.catch()
}

// CreateField ...
func (p *PDFlib) CreateField(llx, lly, urx, ury float64, name, kind, options string) error {
	cName := C.CString(name)
	cKind := C.CString(kind)
	cOptions := C.CString(options)
	C._PDF_create_field(p.val, C.double(llx), C.double(lly), C.double(urx), C.double(ury), cName, 0, cKind, cOptions)
	C.free(unsafe.Pointer(cOptions))
	C.free(unsafe.Pointer(cKind))
	C.free(unsafe.Pointer(cName))
	return p.catch()
}

// CreateFieldgroup ...
func (p *PDFlib) CreateFieldgroup(name, options string) error {
	cName := C.CString(name)
	cOptions := C.CString(options)
	C._PDF_create_fieldgroup(p.val, cName, 0, cOptions)
	C.free(unsafe.Pointer(cOptions))
	C.free(unsafe.Pointer(cName))
	return p.catch()
}

// CreateGstate ...
func (p *PDFlib) CreateGstate(options string) (int, error) {
	cOptions := C.CString(options)
	ret := int(C._PDF_create_gstate(p.val, cOptions))
	C.free(unsafe.Pointer(cOptions))
	return ret, p.catch()
}

// CreatePvf ...
func (p *PDFlib) CreatePvf(filename string, data []byte, options string) error {
	cFilename := C.CString(filename)
	cOptions := C.CString(options)
	C._PDF_create_pvf(p.val, cFilename, 0, unsafe.Pointer(&data[0]), C.size_t(len(data)), cOptions)
	C.free(unsafe.Pointer(cOptions))
	C.free(unsafe.Pointer(cFilename))
	return p.catch()
}

// CreateTextflow ...
func (p *PDFlib) CreateTextflow(text, options string) (int, error) {
	cText := C.CString(text)
	cOptions := C.CString(options)
	ret := int(C._PDF_create_textflow(p.val, cText, 0, cOptions))
	C.free(unsafe.Pointer(cOptions))
	C.free(unsafe.Pointer(cText))
	return ret, p.catch()
}

// CurveTo ...
func (p *PDFlib) CurveTo(x1, y1, x2, y2, x3, y3 float64) error {
	C._PDF_curveto(p.val, C.double(x1), C.double(y1), C.double(x2), C.double(y2), C.double(x3), C.double(y3))
	return p.catch()
}

// DefineLayer ...
func (p *PDFlib) DefineLayer(name, options string) (int, error) {
	cName := C.CString(name)
	cOptions := C.CString(options)
	ret := int(C._PDF_define_layer(p.val, cName, 0, cOptions))
	C.free(unsafe.Pointer(cOptions))
	C.free(unsafe.Pointer(cName))
	return ret, p.catch()
}

// Delete ...
func (p *PDFlib) Delete() {
	C._PDF_delete(p.val)
}

// DeletePath ...
func (p *PDFlib) DeletePath(path int) error {
	C._PDF_delete_path(p.val, C.int(path))
	return p.catch()
}

// DeletePvf ...
func (p *PDFlib) DeletePvf(filename string) error {
	cFilename := C.CString(filename)
	C._PDF_delete_pvf(p.val, cFilename, 0)
	C.free(unsafe.Pointer(cFilename))
	return p.catch()
}

// DeleteTable ...
func (p *PDFlib) DeleteTable(table int, options string) error {
	cOptions := C.CString(options)
	C._PDF_delete_table(p.val, C.int(table), cOptions)
	C.free(unsafe.Pointer(cOptions))
	return p.catch()
}

// DeleteTextflow ...
func (p *PDFlib) DeleteTextflow(textflow int) error {
	C._PDF_delete_textflow(p.val, C.int(textflow))
	return p.catch()
}

// DrawPath ...
func (p *PDFlib) DrawPath(path int, x, y float64, options string) error {
	cOptions := C.CString(options)
	C._PDF_draw_path(p.val, C.int(path), C.double(x), C.double(y), cOptions)
	C.free(unsafe.Pointer(cOptions))
	return p.catch()
}

// Ellipse ...
func (p *PDFlib) Ellipse(x, y, rx, ry float64) error {
	C._PDF_ellipse(p.val, C.double(x), C.double(y), C.double(rx), C.double(ry))
	return p.catch()
}

// EndDocument ...
func (p *PDFlib) EndDocument(options string) error {
	cOptions := C.CString(options)
	C._PDF_end_document(p.val, cOptions)
	C.free(unsafe.Pointer(cOptions))
	return p.catch()
}

// EndFont ...
func (p *PDFlib) EndFont() error {
	C._PDF_end_font(p.val)
	return p.catch()
}

// EndGlyph ...
func (p *PDFlib) EndGlyph() error {
	C._PDF_end_glyph(p.val)
	return p.catch()
}

// EndItem ...
func (p *PDFlib) EndItem(id int) error {
	C._PDF_end_item(p.val, C.int(id))
	return p.catch()
}

// EndLayer ...
func (p *PDFlib) EndLayer() error {
	C._PDF_end_layer(p.val)
	return p.catch()
}

// EndMc ...
func (p *PDFlib) EndMc() error {
	C._PDF_end_mc(p.val)
	return p.catch()
}

// EndPageExt ...
func (p *PDFlib) EndPageExt(options string) error {
	cOptions := C.CString(options)
	C._PDF_end_page_ext(p.val, cOptions)
	C.free(unsafe.Pointer(cOptions))
	return p.catch()
}

// EndPattern ...
func (p *PDFlib) EndPattern() error {
	C._PDF_end_pattern(p.val)
	return p.catch()
}

// EndTemplateExt ...
func (p *PDFlib) EndTemplateExt(w, h float64) error {
	C._PDF_end_template_ext(p.val, C.double(w), C.double(h))
	return p.catch()
}

// EndPath ...
func (p *PDFlib) EndPath() error {
	C._PDF_endpath(p.val)
	return p.catch()
}

// Fill ...
func (p *PDFlib) Fill() error {
	C._PDF_fill(p.val)
	return p.catch()
}

// FillImageblock ...
func (p *PDFlib) FillImageblock(page int, blockname string, image int, options string) (int, error) {
	cBlockname := C.CString(blockname)
	cOptions := C.CString(options)
	ret := int(C._PDF_fill_imageblock(p.val, C.int(page), cBlockname, C.int(image), cOptions))
	C.free(unsafe.Pointer(cOptions))
	C.free(unsafe.Pointer(cBlockname))
	return ret, p.catch()
}

// FillPdfblock ...
func (p *PDFlib) FillPdfblock(page int, blockname string, content int, options string) (int, error) {
	cBlockname := C.CString(blockname)
	cOptions := C.CString(options)
	ret := int(C._PDF_fill_pdfblock(p.val, C.int(page), cBlockname, C.int(content), cOptions))
	C.free(unsafe.Pointer(cOptions))
	C.free(unsafe.Pointer(cBlockname))
	return ret, p.catch()
}

// FillStroke ...
func (p *PDFlib) FillStroke() error {
	C._PDF_fill_stroke(p.val)
	return p.catch()
}

// FillTextblock ...
func (p *PDFlib) FillTextblock(page int, blockname, text, options string) (int, error) {
	cBlockname := C.CString(blockname)
	cText := C.CString(text)
	cOptions := C.CString(options)
	ret := int(C._PDF_fill_textblock(p.val, C.int(page), cBlockname, cText, 0, cOptions))
	C.free(unsafe.Pointer(cOptions))
	C.free(unsafe.Pointer(cText))
	C.free(unsafe.Pointer(cBlockname))
	return ret, p.catch()
}

// FitGraphics places vector graphics on a content stream, subject to various options.
func (p *PDFlib) FitGraphics(graphics int, x, y float64, options string) error {
	cOptions := C.CString(options)
	C._PDF_fit_graphics(p.val, C.int(graphics), C.double(x), C.double(y), cOptions)
	C.free(unsafe.Pointer(cOptions))
	return p.catch()
}

// FitImage ...
func (p *PDFlib) FitImage(image int, x, y float64, options string) error {
	cOptions := C.CString(options)
	C._PDF_fit_image(p.val, C.int(image), C.double(x), C.double(y), cOptions)
	C.free(unsafe.Pointer(cOptions))
	return p.catch()
}

// FitPdiPage ...
func (p *PDFlib) FitPdiPage(page int, x, y float64, options string) error {
	cOptions := C.CString(options)
	C._PDF_fit_pdi_page(p.val, C.int(page), C.double(x), C.double(y), cOptions)
	C.free(unsafe.Pointer(cOptions))
	return p.catch()
}

// FitTable ...
func (p *PDFlib) FitTable(table int, llx, lly, urx, ury float64, options string) (string, error) {
	cOptions := C.CString(options)
	ret := C.GoString(C._PDF_fit_table(p.val, C.int(table), C.double(llx), C.double(lly), C.double(urx), C.double(ury), cOptions))
	C.free(unsafe.Pointer(cOptions))
	return ret, p.catch()
}

// FitTextflow ...
func (p *PDFlib) FitTextflow(textflow int, llx, lly, urx, ury float64, options string) (string, error) {
	cOptions := C.CString(options)
	ret := C.GoString(C._PDF_fit_textflow(p.val, C.int(textflow), C.double(llx), C.double(lly), C.double(urx), C.double(ury), cOptions))
	C.free(unsafe.Pointer(cOptions))
	return ret, p.catch()
}

// FitTextline ...
func (p *PDFlib) FitTextline(text string, x, y float64, options string) error {
	cOptions := C.CString(options)
	C._PDF_fit_textline(p.val, C.CString(text), 0, C.double(x), C.double(y), cOptions)
	C.free(unsafe.Pointer(cOptions))
	return p.catch()
}

// GetBuffer ...
func (p *PDFlib) GetBuffer() ([]byte, int, error) {
	var size C.long
	ret := []byte(C.GoStringN(C.PDF_get_buffer(p.val, &size), C.int(size)))
	return ret, int(size), p.catch()
}

// GetParameter ...
func (p *PDFlib) GetParameter(key string, modifier float64) (string, error) {
	ret := C.GoString(C._PDF_get_parameter(p.val, C.CString(key), C.double(modifier)))
	return ret, p.catch()
}

// GetValue ...
func (p *PDFlib) GetValue(key string, modifier float64) (float64, error) {
	ret := float64(C._PDF_get_value(p.val, C.CString(key), C.double(modifier)))
	return ret, p.catch()
}

// InfoFont ...
func (p *PDFlib) InfoFont(font int, keyword, options string) (float64, error) {
	ret := float64(C._PDF_info_font(p.val, C.int(font), C.CString(keyword), C.CString(options)))
	return ret, p.catch()
}

// InfoGraphics formats vector graphics and query metrics and other properties.
func (p *PDFlib) InfoGraphics(graphics int, keyword, options string) (float64, error) {
	cOptions := C.CString(options)
	ret := float64(C._PDF_info_graphics(p.val, C.int(graphics), C.CString(keyword), cOptions))
	C.free(unsafe.Pointer(cOptions))
	return ret, p.catch()
}

// InfoImage ...
func (p *PDFlib) InfoImage(image int, keyword, options string) (float64, error) {
	cOptions := C.CString(options)
	ret := float64(C._PDF_info_image(p.val, C.int(image), C.CString(keyword), cOptions))
	C.free(unsafe.Pointer(cOptions))
	return ret, p.catch()
}

// InfoMatchbox ...
func (p *PDFlib) InfoMatchbox(boxname string, num int, keyword string) (float64, error) {
	cKeyword := C.CString(keyword)
	ret := float64(C._PDF_info_matchbox(p.val, C.CString(boxname), 0, C.int(num), cKeyword))
	C.free(unsafe.Pointer(cKeyword))
	return ret, p.catch()
}

// InfoPath ...
func (p *PDFlib) InfoPath(path int, keyword, options string) (float64, error) {
	cOptions := C.CString(options)
	cKeyword := C.CString(keyword)
	ret := float64(C._PDF_info_path(p.val, C.int(path), cKeyword, cOptions))
	C.free(unsafe.Pointer(cKeyword))
	C.free(unsafe.Pointer(cOptions))
	return ret, p.catch()
}

// InfoPdiPage ...
func (p *PDFlib) InfoPdiPage(page int, keyword, options string) (float64, error) {
	cOptions := C.CString(options)
	cKeyword := C.CString(keyword)
	ret := float64(C._PDF_info_pdi_page(p.val, C.int(page), cKeyword, cOptions))
	C.free(unsafe.Pointer(cKeyword))
	C.free(unsafe.Pointer(cOptions))
	return ret, p.catch()
}

// InfoTable ...
func (p *PDFlib) InfoTable(table int, keyword string) (float64, error) {
	cKeyword := C.CString(keyword)
	ret := float64(C._PDF_info_table(p.val, C.int(table), cKeyword))
	C.free(unsafe.Pointer(cKeyword))
	return ret, p.catch()
}

// InfoTextflow ...
func (p *PDFlib) InfoTextflow(textflow int, keyword string) (float64, error) {
	cKeyword := C.CString(keyword)
	ret := float64(C._PDF_info_textflow(p.val, C.int(textflow), cKeyword))
	C.free(unsafe.Pointer(cKeyword))
	return ret, p.catch()
}

// InfoTextline ...
func (p *PDFlib) InfoTextline(text, keyword, options string) (float64, error) {
	cText := C.CString(text)
	cKeyword := C.CString(keyword)
	cOptions := C.CString(options)
	ret := float64(C._PDF_info_textline(p.val, cText, 0, cKeyword, cOptions))
	C.free(unsafe.Pointer(cText))
	C.free(unsafe.Pointer(cKeyword))
	C.free(unsafe.Pointer(cOptions))
	return ret, p.catch()
}

// InitGraphics ...
func (p *PDFlib) InitGraphics() error {
	C._PDF_initgraphics(p.val)
	return p.catch()
}

// LineTo ...
func (p *PDFlib) LineTo(x, y float64) error {
	C._PDF_lineto(p.val, C.double(x), C.double(y))
	return p.catch()
}

// Load3dData ...
func (p *PDFlib) Load3dData(filename, options string) (int, error) {
	cFilename := C.CString(filename)
	cOptions := C.CString(options)
	ret := int(C._PDF_load_3ddata(p.val, cFilename, 0, cOptions))
	C.free(unsafe.Pointer(cFilename))
	C.free(unsafe.Pointer(cOptions))
	return ret, p.catch()
}

// LoadFont ...
func (p *PDFlib) LoadFont(fontname, encoding, options string) (int, error) {
	cFontname := C.CString(fontname)
	cEncoding := C.CString(encoding)
	cOptions := C.CString(options)
	ret := int(C._PDF_load_font(p.val, cFontname, 0, cEncoding, cOptions))
	C.free(unsafe.Pointer(cOptions))
	C.free(unsafe.Pointer(cEncoding))
	C.free(unsafe.Pointer(cFontname))
	return ret, p.catch()
}

// LoadGraphics opens a disk-based or virtual vector graphics file subject to various options
func (p *PDFlib) LoadGraphics(graphicstype, filename, options string) (int, error) {
	cGraphicstype := C.CString(graphicstype)
	cFilename := C.CString(filename)
	cOptions := C.CString(options)
	ret := int(C._PDF_load_graphics(p.val, cGraphicstype, cFilename, 0, cOptions))
	C.free(unsafe.Pointer(cOptions))
	C.free(unsafe.Pointer(cFilename))
	C.free(unsafe.Pointer(cGraphicstype))
	return ret, p.catch()
}

// LoadIccProfile ...
func (p *PDFlib) LoadIccProfile(profilename, options string) (int, error) {
	cProfilename := C.CString(profilename)
	cOptions := C.CString(options)
	ret := int(C._PDF_load_iccprofile(p.val, cProfilename, 0, cOptions))
	C.free(unsafe.Pointer(cOptions))
	C.free(unsafe.Pointer(cProfilename))
	return ret, p.catch()
}

// LoadImage ...
func (p *PDFlib) LoadImage(imagetype, filename, options string) (int, error) {
	cImagetype := C.CString(imagetype)
	cFilename := C.CString(filename)
	cOptions := C.CString(options)
	ret := int(C._PDF_load_image(p.val, cImagetype, cFilename, 0, cOptions))
	C.free(unsafe.Pointer(cOptions))
	C.free(unsafe.Pointer(cFilename))
	C.free(unsafe.Pointer(cImagetype))
	return ret, p.catch()
}

// MakeSpotColor ...
func (p *PDFlib) MakeSpotColor(spotname string) (int, error) {
	cSpotname := C.CString(spotname)
	ret := int(C._PDF_makespotcolor(p.val, cSpotname, 0))
	C.free(unsafe.Pointer(cSpotname))
	return ret, p.catch()
}

// McPoint ...
func (p *PDFlib) McPoint(tag, options string) error {
	cTag := C.CString(tag)
	cOptions := C.CString(options)
	C._PDF_mc_point(p.val, cTag, cOptions)
	C.free(unsafe.Pointer(cOptions))
	C.free(unsafe.Pointer(cTag))
	return p.catch()
}

// MoveTo ...
func (p *PDFlib) MoveTo(x, y float64) error {
	C._PDF_moveto(p.val, C.double(x), C.double(y))
	return p.catch()
}

// OpenPdiDocument ...
func (p *PDFlib) OpenPdiDocument(filename, options string) (int, error) {
	cFilename := C.CString(filename)
	cOptions := C.CString(options)
	ret := int(C._PDF_open_pdi_document(p.val, cFilename, 0, cOptions))
	C.free(unsafe.Pointer(cOptions))
	C.free(unsafe.Pointer(cFilename))
	return ret, p.catch()
}

// OpenPdiPage ...
func (p *PDFlib) OpenPdiPage(doc, page int, options string) (int, error) {
	cOptions := C.CString(options)
	ret := int(C._PDF_open_pdi_page(p.val, C.int(doc), C.int(page), cOptions))
	C.free(unsafe.Pointer(cOptions))
	return ret, p.catch()
}

// PcosGetNumber ...
func (p *PDFlib) PcosGetNumber(doc int, path string) (float64, error) {
	cPath := C.CString(path)
	ret := float64(C._PDF_pcos_get_number(p.val, C.int(doc), cPath))
	C.free(unsafe.Pointer(cPath))
	return ret, p.catch()
}

// PcosGetString ...
func (p *PDFlib) PcosGetString(doc int, path string) (string, error) {
	cPath := C.CString(path)
	ret := string(C.GoString(C._PDF_pcos_get_string(p.val, C.int(doc), cPath)))
	C.free(unsafe.Pointer(cPath))
	return ret, p.catch()
}

// PcosGetStream ...
func (p *PDFlib) PcosGetStream(doc int, options, path string) (string, error) {
	cPath := C.CString(path)
	cOptions := C.CString(options)
	ret := "" // string(C.GoString(C._PDF_pcos_get_stream(p.val, C.int(doc), 0, cOptions, cPath)))
	C.free(unsafe.Pointer(cOptions))
	C.free(unsafe.Pointer(cPath))
	return ret, p.catch()
}

// PocaDelete ...
func (p *PDFlib) PocaDelete(container int, options string) error {
	cOptions := C.CString(options)
	C._PDF_poca_delete(p.val, C.int(container), cOptions)
	C.free(unsafe.Pointer(cOptions))
	return p.catch()
}

// PocaInsert ...
func (p *PDFlib) PocaInsert(container int, options string) error {
	cOptions := C.CString(options)
	C._PDF_poca_insert(p.val, C.int(container), cOptions)
	C.free(unsafe.Pointer(cOptions))
	return p.catch()
}

// PocaNew ...
func (p *PDFlib) PocaNew(options string) (int, error) {
	cOptions := C.CString(options)
	ret := int(C._PDF_poca_new(p.val, cOptions))
	C.free(unsafe.Pointer(cOptions))
	return ret, p.catch()
}

// PocaRemove ...
func (p *PDFlib) PocaRemove(container int, options string) error {
	cOptions := C.CString(options)
	C._PDF_poca_remove(p.val, C.int(container), cOptions)
	C.free(unsafe.Pointer(cOptions))
	return p.catch()
}

// ProcessPdi ...
func (p *PDFlib) ProcessPdi(doc, page int, options string) (int, error) {
	cOptions := C.CString(options)
	ret := int(C._PDF_process_pdi(p.val, C.int(doc), C.int(page), cOptions))
	C.free(unsafe.Pointer(cOptions))
	return ret, p.catch()
}

// RCurveTo ...
func (p *PDFlib) RCurveTo(x1, y1, x2, y2, x3, y3 float64) error {
	C._PDF_rcurveto(p.val, C.double(x1), C.double(x1), C.double(y1), C.double(x2), C.double(y2), C.double(y3))
	return p.catch()
}

// Rect ...
func (p *PDFlib) Rect(x, y, w, h float64) error {
	C._PDF_rect(p.val, C.double(x), C.double(y), C.double(w), C.double(h))
	return p.catch()
}

// Restore ...
func (p *PDFlib) Restore() error {
	C._PDF_restore(p.val)
	return p.catch()
}

// ResumePage ...
func (p *PDFlib) ResumePage(options string) error {
	cOptions := C.CString(options)
	C._PDF_resume_page(p.val, cOptions)
	C.free(unsafe.Pointer(cOptions))
	return p.catch()
}

// Rotate ...
func (p *PDFlib) Rotate(phi float64) error {
	C._PDF_rotate(p.val, C.double(phi))
	return p.catch()
}

// Save ...
func (p *PDFlib) Save() error {
	C._PDF_save(p.val)
	return p.catch()
}

// Scale ...
func (p *PDFlib) Scale(sx, sy float64) error {
	C._PDF_scale(p.val, C.double(sx), C.double(sy))
	return p.catch()
}

// SetGraphicsOption sets one or more graphics appearance options.
func (p *PDFlib) SetGraphicsOption(options string) error {
	cOptions := C.CString(options)
	C._PDF_set_graphics_option(p.val, cOptions)
	C.free(unsafe.Pointer(cOptions))
	return p.catch()
}

// SetGstate ...
func (p *PDFlib) SetGstate(gstate int) error {
	C._PDF_set_gstate(p.val, C.int(gstate))
	return p.catch()
}

// SetInfo ...
func (p *PDFlib) SetInfo(key, value string) error {
	C._PDF_set_info(p.val, C.CString(key), C.CString(value))
	return p.catch()
}

// SetLayerDependency ...
func (p *PDFlib) SetLayerDependency(kind, options string) error {
	cOptions := C.CString(options)
	C._PDF_set_layer_dependency(p.val, C.CString(kind), cOptions)
	C.free(unsafe.Pointer(cOptions))
	return p.catch()
}

// SetOption ...
func (p *PDFlib) SetOption(options string) error {
	cOptions := C.CString(options)
	C._PDF_set_option(p.val, cOptions)
	C.free(unsafe.Pointer(cOptions))
	return p.catch()
}

// SetParameter ...
func (p *PDFlib) SetParameter(key, value string) error {
	cKey := C.CString(key)
	cValue := C.CString(value)
	C._PDF_set_parameter(p.val, cKey, cValue)
	C.free(unsafe.Pointer(cValue))
	C.free(unsafe.Pointer(cKey))
	return p.catch()
}

// SetTextPos ...
func (p *PDFlib) SetTextPos(x, y float64) error {
	C._PDF_set_text_pos(p.val, C.double(x), C.double(y))
	return p.catch()
}

// SetValue ...
func (p *PDFlib) SetValue(key string, value float64) error {
	C._PDF_set_value(p.val, C.CString(key), C.double(value))
	return p.catch()
}

// SetColor ...
func (p *PDFlib) SetColor(fstype, colorspace string, c1, c2, c3, c4 float64) error {
	cFstype := C.CString(fstype)
	cColorspace := C.CString(colorspace)
	C._PDF_setcolor(p.val, cFstype, cColorspace, C.double(c1), C.double(c2), C.double(c3), C.double(c4))
	C.free(unsafe.Pointer(cColorspace))
	C.free(unsafe.Pointer(cFstype))
	return p.catch()
}

// SetDash ...
func (p *PDFlib) SetDash(b, w float64) error {
	C._PDF_setdash(p.val, C.double(b), C.double(w))
	return p.catch()
}

// SetDashPattern ...
func (p *PDFlib) SetDashPattern(options string) error {
	cOptions := C.CString(options)
	C._PDF_setdashpattern(p.val, cOptions)
	C.free(unsafe.Pointer(cOptions))
	return p.catch()
}

// SetFlat ...
func (p *PDFlib) SetFlat(flatness float64) error {
	C._PDF_setflat(p.val, C.double(flatness))
	return p.catch()
}

// SetFont ...
func (p *PDFlib) SetFont(font int, fontsize float64) error {
	C._PDF_setfont(p.val, C.int(font), C.double(fontsize))
	return p.catch()
}

// SetLinecap ...
func (p *PDFlib) SetLinecap(linecap int) error {
	C._PDF_setlinecap(p.val, C.int(linecap))
	return p.catch()
}

// SetLinejoin ...
func (p *PDFlib) SetLinejoin(linejoin int) error {
	C._PDF_setlinejoin(p.val, C.int(linejoin))
	return p.catch()
}

// SetLinewidth ...
func (p *PDFlib) SetLinewidth(width float64) error {
	C._PDF_setlinewidth(p.val, C.double(width))
	return p.catch()
}

// SetMatrix ...
func (p *PDFlib) SetMatrix(a, b, c, d, e, f float64) error {
	C._PDF_setmatrix(p.val, C.double(a), C.double(b), C.double(c), C.double(d), C.double(e), C.double(f))
	return p.catch()
}

// SetMiterLimit ...
func (p *PDFlib) SetMiterLimit(miter float64) error {
	C._PDF_setmiterlimit(p.val, C.double(miter))
	return p.catch()
}

// Shading ...
func (p *PDFlib) Shading(shtype string, x0, y0, x1, y1, c1, c2, c3, c4 float64, options string) (int, error) {
	cOptions := C.CString(options)
	cShtype := C.CString(shtype)
	ret := int(C._PDF_shading(p.val, cShtype, C.double(x0), C.double(y0), C.double(x1), C.double(y1), C.double(c1), C.double(c2), C.double(c3), C.double(c4), cOptions))
	C.free(unsafe.Pointer(cShtype))
	C.free(unsafe.Pointer(cOptions))
	return ret, p.catch()
}

// ShadingPattern ...
func (p *PDFlib) ShadingPattern(shading int, options string) (int, error) {
	cOptions := C.CString(options)
	ret := int(C._PDF_shading_pattern(p.val, C.int(shading), cOptions))
	C.free(unsafe.Pointer(cOptions))
	return ret, p.catch()
}

// Shfill ...
func (p *PDFlib) Shfill(shading int) error {
	C._PDF_shfill(p.val, C.int(shading))
	return p.catch()
}

// Show ...
func (p *PDFlib) Show(text string) error {
	C._PDF_show(p.val, C.CString(text))
	return p.catch()
}

// ShowXY ...
func (p *PDFlib) ShowXY(text string, x, y float64) error {
	C._PDF_show_xy(p.val, C.CString(text), C.double(x), C.double(y))
	return p.catch()
}

// Skew ...
func (p *PDFlib) Skew(alpha, beta float64) error {
	C._PDF_skew(p.val, C.double(alpha), C.double(beta))
	return p.catch()
}

// StringWidth ...
func (p *PDFlib) StringWidth(text string, font int, fontsize float64) (float64, error) {
	ret := float64(C._PDF_stringwidth(p.val, C.CString(text), C.int(font), C.double(fontsize)))
	return ret, p.catch()
}

// Stroke ...
func (p *PDFlib) Stroke() error {
	C._PDF_stroke(p.val)
	return p.catch()
}

// SuspendPage ...
func (p *PDFlib) SuspendPage(options string) error {
	cOptions := C.CString(options)
	C._PDF_suspend_page(p.val, cOptions)
	C.free(unsafe.Pointer(cOptions))
	return p.catch()
}

// Translate ...
func (p *PDFlib) Translate(tx, ty float64) error {
	C._PDF_translate(p.val, C.double(tx), C.double(ty))
	return p.catch()
}
