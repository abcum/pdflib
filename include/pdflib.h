/*---------------------------------------------------------------------------*
 |          Copyright (c) 1997-2012 PDFlib GmbH. All rights reserved.        |
 +---------------------------------------------------------------------------+
 |    This software may not be copied or distributed except as expressly     |
 |    authorized by PDFlib GmbH's general license agreement or a custom      |
 |    license agreement signed by PDFlib GmbH.                               |
 |    For more information about licensing please refer to www.pdflib.com.   |
 *---------------------------------------------------------------------------*/

/* $Id: pdflib.h,v 1.357.2.62 2013/06/17 19:02:03 rjs Exp $
 *
 * Public function declarations for PDFlib, PDFlib+PDI, and PPS;
 * see PDFlib API reference for details.
 *
 */

#ifndef PDFLIB_H
#define PDFLIB_H

/* Make our declarations C++ compatible */
#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <setjmp.h>

#define PDFLIB_PRODUCTNAME      "PDFlib"

/*
 * The version defines below can be used to check the version of the
 * include file against the library.
 */

#define PDFLIB_MAJORVERSION	8	        /* major version number */
#define PDFLIB_MINORVERSION	0       	/* minor version number */
#define PDFLIB_REVISION		6       	/* revision number */
#define PDFLIB_SHORT_VERSIONSTRING "8"          /* short version number */
#define PDFLIB_LONG_VERSIONSTRING  "8.0.6" /* full version number*/


/*
 * ----------------------------------------------------------------------
 * Setup, mostly Windows calling conventions and DLL stuff
 * ----------------------------------------------------------------------
 */

#if defined(WIN32) && !defined(PDFLIB_CALL)
    #define PDFLIB_CALL	__cdecl
#endif

#undef PDFLIB_API
#if defined(WIN32)

    #ifdef PDFLIB_EXPORTS
    #define PDFLIB_API __declspec(dllexport) /* prepare a DLL (internal use) */

    #elif defined(PDFLIB_DLL)

    #define PDFLIB_API __declspec(dllimport) /* PDFlib clients: import  DLL */
    #endif	/* PDFLIB_DLL */

#else
    #if __GNUC__ >= 4
	#define PDFLIB_API __attribute__ ((visibility("default")))
    #elif (defined(__SUNPRO_CC) && __SUNPRO_CC >= 0x550) \
	   || (defined(__SUNPRO_C) && __SUNPRO_C >= 0x550)
	#define PDFLIB_API __global
    #elif defined(HPUX_HIDDEN_DEF)
	#define PDFLIB_API __declspec(dllexport)
    #endif
#endif /* WIN32 */

#ifndef PDFLIB_CALL
    #define PDFLIB_CALL	/* */	/* default: no special calling conventions */
#endif

#ifndef PDFLIB_API
    #define PDFLIB_API /* */	 /* default: generate or use static library */
#endif

#if !defined(PDF)  || defined(ACTIVEX)
       typedef struct PDF_s PDF;
#endif /* !PDF */

/* The API structure with function pointers. */
typedef struct PDFlib_api_s PDFlib_api;


/*
 * ----------------------------------------------------------------------
 * Function prototypes for all supported API functions
 * ----------------------------------------------------------------------
 */

/* Activate a previously created structure element or other content item. */
PDFLIB_API void PDFLIB_CALL
PDF_activate_item(PDF *p, int id);

/* Deprecated, use PDF_create_bookmark(). */
PDFLIB_API int PDFLIB_CALL
PDF_add_bookmark(PDF *p, const char *text, int parent, int open);

/* Deprecated, use PDF_create_bookmark(). */
PDFLIB_API int PDFLIB_CALL
PDF_add_bookmark2(PDF *p, const char *text, int len, int parent, int open);

/* Deprecated, use PDF_create_action() and PDF_create_annotation(). */
PDFLIB_API void PDFLIB_CALL
PDF_add_launchlink(PDF *p, double llx, double lly, double urx, double ury,
    const char *filename);

/* Deprecated, use PDF_create_action() and PDF_create_annotation(). */
PDFLIB_API void PDFLIB_CALL
PDF_add_locallink(PDF *p, double llx, double lly, double urx, double ury,
    int page, const char *optlist);

/* Create a named destination on a page in the document. */
PDFLIB_API void PDFLIB_CALL
PDF_add_nameddest(PDF *p, const char *name, int len, const char *optlist);

/* Deprecated, use PDF_create_annotation(). */
PDFLIB_API void PDFLIB_CALL
PDF_add_note(PDF *p, double llx, double lly, double urx, double ury,
    const char *contents, const char *title, const char *icon, int open);

/* Deprecated, use PDF_create_annotation(). */
PDFLIB_API void PDFLIB_CALL
PDF_add_note2(PDF *p, double llx, double lly, double urx, double ury,
    const char *contents, int len_cont, const char *title, int len_title,
    const char *icon, int open);

/* Add a point to a new or existing path object.
   Returns: A path handle which can be used in subsequent path-related calls.
*/
PDFLIB_API int PDFLIB_CALL
PDF_add_path_point(PDF *p, int path, double x, double y,
    const char *type, const char *optlist);

/* Deprecated, use PDF_create_action() and PDF_create_annotation(). */
PDFLIB_API void PDFLIB_CALL
PDF_add_pdflink(PDF *p, double llx, double lly, double urx, double ury,
    const char *filename, int page, const char *optlist);

/* Add a file to a portfolio folder or a package (requires PDF 1.7).
   Returns: -1 (in PHP: 0) on error, and 1 otherwise.
*/
PDFLIB_API int PDFLIB_CALL
PDF_add_portfolio_file(PDF *p, int folder, const char *filename, int len,
    const char *optlist);

/* Add a folder to a new or existing portfolio (requires PDF 1.7ext3).
   Returns: A folder handle which can be used in subsequent
   portfolio-related calls.
*/
PDFLIB_API int PDFLIB_CALL
PDF_add_portfolio_folder(PDF *p, int parent, const char *foldername, int len,
    const char *optlist);

/* Add a cell to a new or existing table.
   Returns: A table handle which can be used in subsequent table-related calls.
*/
PDFLIB_API int PDFLIB_CALL
PDF_add_table_cell(PDF *p, int table, int column, int row, const char *text,
    int len, const char *optlist);

/* Create a Textflow object, or add text and explicit options to an existing
   Textflow.
   Returns: A Textflow handle, or -1 (in PHP: 0) on error.
*/
PDFLIB_API int PDFLIB_CALL
PDF_add_textflow(PDF *p, int textflow, const char *text, int len,
    const char *optlist);

/* Add an image as thumbnail for the current page. */
PDFLIB_API void PDFLIB_CALL
PDF_add_thumbnail(PDF *p, int image);

/* Deprecated, use PDF_create_action() and PDF_create_annotation(). */
PDFLIB_API void PDFLIB_CALL
PDF_add_weblink(PDF *p, double llx, double lly, double urx, double ury,
    const char *url);

/* Align the coordinate system with a relative vector. */
PDFLIB_API void PDFLIB_CALL
PDF_align(PDF *p, double dx, double dy);

/* Draw a counterclockwise circular arc segment. */
PDFLIB_API void PDFLIB_CALL
PDF_arc(PDF *p, double x, double y, double r, double alpha, double beta);

/* Draw a clockwise circular arc segment. */
PDFLIB_API void PDFLIB_CALL
PDF_arcn(PDF *p, double x, double y, double r, double alpha, double beta);

/* Deprecated, use PDF_create_annotation(). */
PDFLIB_API void PDFLIB_CALL
PDF_attach_file(PDF *p, double llx, double lly, double urx, double ury,
    const char *filename, const char *description, const char *author,
    const char *mimetype, const char *icon);

/* Deprecated, use PDF_create_annotation(). */
PDFLIB_API void PDFLIB_CALL
PDF_attach_file2(PDF *p, double llx, double lly, double urx, double ury,
    const char *filename, int len_filename, const char *description,
    int len_descr, const char *author, int len_auth, const char *mimetype,
    const char *icon);

/* Create a new PDF document subject to various options.
   Returns: -1 (in PHP: 0) on error, and 1 otherwise.
*/
PDFLIB_API int PDFLIB_CALL
PDF_begin_document(PDF *p, const char *filename, int len, const char *optlist);

/* Create a new PDF document subject to various options. */
typedef size_t (*writeproc_t)(PDF *p1, void *data, size_t size);
PDFLIB_API void PDFLIB_CALL
PDF_begin_document_callback(PDF *p, writeproc_t writeproc, const char *optlist);

/* Start a Type 3 font definition. */
PDFLIB_API void PDFLIB_CALL
PDF_begin_font(PDF *p, const char *fontname, int len,
    double a, double b, double c, double d, double e, double f,
    const char *optlist);

/* Start a glyph definition for a Type 3 font. */
PDFLIB_API void PDFLIB_CALL
PDF_begin_glyph(PDF *p, const char *glyphname, double wx,
    double llx, double lly, double urx, double ury);

/* Open a structure element or other content item with attributes supplied
   as options.
   Returns: An item handle.
*/
PDFLIB_API int PDFLIB_CALL
PDF_begin_item(PDF *p, const char *tag, const char *optlist);

/* Start a layer for subsequent output on the page (requires PDF 1.5). */
PDFLIB_API void PDFLIB_CALL
PDF_begin_layer(PDF *p, int layer);

/* Begin a marked content sequence with optional properties. */
PDFLIB_API void PDFLIB_CALL
PDF_begin_mc(PDF *p, const char *tag, const char *optlist);

/* Deprecated, use PDF_begin_page_ext(). */
PDFLIB_API void PDFLIB_CALL
PDF_begin_page(PDF *p, double width, double height);

/* Add a new page to the document, and specify various options. */
PDFLIB_API void PDFLIB_CALL
PDF_begin_page_ext(PDF *p, double width, double height, const char *optlist);

/* Start a pattern definition.
   Returns: A pattern handle.
*/
PDFLIB_API int PDFLIB_CALL
PDF_begin_pattern(PDF *p,
    double width, double height, double xstep, double ystep, int painttype);

/* Deprecated, use PDF_begin_template_ext(). */
PDFLIB_API int PDFLIB_CALL
PDF_begin_template(PDF *p, double width, double height);

/* Start a template definition.
   Returns: A template handle.
*/
PDFLIB_API int PDFLIB_CALL
PDF_begin_template_ext(PDF *p, double width, double height,
    const char *optlist);

/* Deprecated, and not required. */
PDFLIB_API void PDFLIB_CALL
PDF_boot(void);

/* Check the validity of a PDFlib context (unsupported). */
PDFLIB_API int PDFLIB_CALL
PDF_check_context(PDF *p);

/* Draw a circle. */
PDFLIB_API void PDFLIB_CALL
PDF_circle(PDF *p, double x, double y, double r);

/* Draw a circular arc segment defined by three points. */
PDFLIB_API void PDFLIB_CALL
PDF_circular_arc(PDF *p, double x_1, double y_1, double x_2, double y_2);

/* Use the current path as clipping path, and terminate the path. */
PDFLIB_API void PDFLIB_CALL
PDF_clip(PDF *p);

/* Deprecated, use PDF_end_document(). */
PDFLIB_API void PDFLIB_CALL
PDF_close(PDF *p);

/* Close an open font handle which has not yet been used in the document. */
PDFLIB_API void PDFLIB_CALL
PDF_close_font(PDF *p, int font);

/* Close an image. */
PDFLIB_API void PDFLIB_CALL
PDF_close_image(PDF *p, int image);

/* Deprecated, use PDF_close_pdi_document(). */
PDFLIB_API void PDFLIB_CALL
PDF_close_pdi(PDF *p, int doc);

/* Close all open PDI page handles, and close the input PDF document. */
PDFLIB_API void PDFLIB_CALL
PDF_close_pdi_document(PDF *p, int doc);

/* Close the page handle and free all page-related resources. */
PDFLIB_API void PDFLIB_CALL
PDF_close_pdi_page(PDF *p, int page);

/* Close the current path. */
PDFLIB_API void PDFLIB_CALL
PDF_closepath(PDF *p);

/* Close the path, fill, and stroke it. */
PDFLIB_API void PDFLIB_CALL
PDF_closepath_fill_stroke(PDF *p);

/* Close the path, and stroke it. */
PDFLIB_API void PDFLIB_CALL
PDF_closepath_stroke(PDF *p);

/* Apply a transformation matrix to the current coordinate system. */
PDFLIB_API void PDFLIB_CALL
PDF_concat(PDF *p, double a, double b, double c, double d, double e, double f);

/* Print text at the next line. */
PDFLIB_API void PDFLIB_CALL
PDF_continue_text(PDF *p, const char *text);

/* Same as PDF_continue_text(), but with explicit string length. */
PDFLIB_API void PDFLIB_CALL
PDF_continue_text2(PDF *p, const char *text, int len);

/* Create a 3D view (requires PDF 1.6).
   Returns: A 3D view handle, or -1 (in PHP: 0) on error.
*/
PDFLIB_API int PDFLIB_CALL
PDF_create_3dview(PDF *p, const char *username, int len, const char *optlist);

/* Create an action which can be applied to various objects and events.
   Returns: An action handle.
*/
PDFLIB_API int PDFLIB_CALL
PDF_create_action(PDF *p, const char *type, const char *optlist);

/* Create an annotation on the current page. */
PDFLIB_API void PDFLIB_CALL
PDF_create_annotation(PDF *p, double llx, double lly, double urx, double ury,
    const char *type, const char *optlist);

/* Create a bookmark subject to various options.
   Returns: A handle for the generated bookmark.
*/
PDFLIB_API int PDFLIB_CALL
PDF_create_bookmark(PDF *p, const char *text, int len, const char *optlist);

/* Create a form field on the current page subject to various options. */
PDFLIB_API void PDFLIB_CALL
PDF_create_field(PDF *p, double llx, double lly, double urx, double ury,
    const char *name, int len, const char *type, const char *optlist);

/* Create a form field group subject to various options. */
PDFLIB_API void PDFLIB_CALL
PDF_create_fieldgroup(PDF *p, const char *name, int len, const char *optlist);

/* Create a graphics state object subject to various options.
   Returns: A graphics state handle.
*/
PDFLIB_API int PDFLIB_CALL
PDF_create_gstate(PDF *p, const char *optlist);

/* Create a named virtual read-only file from data provided in memory. */
PDFLIB_API void PDFLIB_CALL
PDF_create_pvf(PDF *p, const char *filename, int len,
    const void *data, size_t size, const char *optlist);

/* Create a Textflow object from text contents, inline options, and explicit
   options.
   Returns: A Textflow handle, or -1 (in PHP: 0) on error.
*/
PDFLIB_API int PDFLIB_CALL
PDF_create_textflow(PDF *p, const char *text, int len, const char *optlist);

/* Draw a Bezier curve from the current point, using three more control
   points. */
PDFLIB_API void PDFLIB_CALL
PDF_curveto(PDF *p,
    double x_1, double y_1, double x_2, double y_2, double x_3, double y_3);

/* Create a new layer definition (requires PDF 1.5).
   Returns: A layer handle which can be used in subsequent layer-related calls.
*/
PDFLIB_API int PDFLIB_CALL
PDF_define_layer(PDF *p, const char *name, int len, const char *optlist);

/* Deflate a Unicode string (UTF-16 or UTF-32) to a byte string (unsupported)
*/
PDFLIB_API const char * PDFLIB_CALL
PDF_deflate_unicode(PDF *p, const char *utfstring, int len, int charsize,
    int *highchar);

/* Delete a PDFlib object and free all internal resources. */
PDFLIB_API void PDFLIB_CALL
PDF_delete(PDF *p);

/* Delete a path object. */
PDFLIB_API void PDFLIB_CALL
PDF_delete_path(PDF *p, int path);

/* Delete a named virtual file and free its data structures (but not the
   contents).
   Returns: -1 (in PHP: 0) if the virtual file exists but is locked, and
   1 otherwise.
 */
PDFLIB_API int PDFLIB_CALL
PDF_delete_pvf(PDF *p, const char *filename, int len);

/* Delete a table and all associated data structures. */
PDFLIB_API void PDFLIB_CALL
PDF_delete_table(PDF *p, int table, const char *optlist);

/* Delete a Textflow and all associated data structures. */
PDFLIB_API void PDFLIB_CALL
PDF_delete_textflow(PDF *p, int textflow);

/* Draw a path object. */
PDFLIB_API void PDFLIB_CALL PDF_draw_path(PDF *p, int path, double x, double y,
    const char *optlist);

/* Draw an ellipse. */
PDFLIB_API void PDFLIB_CALL
PDF_ellipse(PDF *p, double x, double y, double rx, double ry);

/* Add a glyph name and/or Unicode value to a custom 8-bit encoding. */
PDFLIB_API void PDFLIB_CALL
PDF_encoding_set_char(PDF *p, const char *encoding, int slot,
    const char *glyphname, int uv);

/* Close the generated PDF document and apply various options. */
PDFLIB_API void PDFLIB_CALL
PDF_end_document(PDF *p, const char *optlist);

/* Terminate a Type 3 font definition. */
PDFLIB_API void PDFLIB_CALL
PDF_end_font(PDF *p);

/* Terminate a glyph definition for a Type 3 font. */
PDFLIB_API void PDFLIB_CALL
PDF_end_glyph(PDF *p);

/* Close a structure element or other content item. */
PDFLIB_API void PDFLIB_CALL
PDF_end_item(PDF *p, int id);

/* Deactivate all active layers (requires PDF 1.5). */
PDFLIB_API void PDFLIB_CALL
PDF_end_layer(PDF *p);

/* End the least recently opened marked content sequence. */
PDFLIB_API void PDFLIB_CALL
PDF_end_mc(PDF *p);

/* Deprecated, use PDF_end_page_ext(). */
PDFLIB_API void PDFLIB_CALL
PDF_end_page(PDF *p);

/* Finish a page and apply various options. */
PDFLIB_API void PDFLIB_CALL
PDF_end_page_ext(PDF *p, const char *optlist);

/* Finish a pattern definition. */
PDFLIB_API void PDFLIB_CALL
PDF_end_pattern(PDF *p);

/* Deprecated, use PDF_end_template_ext(). */
PDFLIB_API void PDFLIB_CALL
PDF_end_template(PDF *p);

/* Finish a template definition. */
PDFLIB_API void PDFLIB_CALL
PDF_end_template_ext(PDF *p, double width, double height);

/* End the current path without filling or stroking it. */
PDFLIB_API void PDFLIB_CALL
PDF_endpath(PDF *p);

/* Fill the interior of the path with the current fill color. */
PDFLIB_API void PDFLIB_CALL
PDF_fill(PDF *p);

/* Fill an image block with variable data according to its properties.
   Returns: -1 (in PHP: 0) on error, and 1 otherwise.
*/
PDFLIB_API int PDFLIB_CALL
PDF_fill_imageblock(PDF *p, int page, const char *blockname,
    int image, const char *optlist);

/* Fill a PDF block with variable data according to its properties.
   Returns: -1 (in PHP: 0) on error, and 1 otherwise.
*/
PDFLIB_API int PDFLIB_CALL
PDF_fill_pdfblock(PDF *p, int page, const char *blockname,
    int contents, const char *optlist);

/* Fill and stroke the path with the current fill and stroke color. */
PDFLIB_API void PDFLIB_CALL
PDF_fill_stroke(PDF *p);

/* Fill a Textline or Textflow Block with variable data according to its
   properties.
   Returns: -1 (in PHP: 0) on error, and 1 otherwise.
*/
PDFLIB_API int PDFLIB_CALL
PDF_fill_textblock(PDF *p, int page, const char *blockname,
    const char *text, int len, const char *optlist);

/* Deprecated, use PDF_load_font(). */
PDFLIB_API int PDFLIB_CALL
PDF_findfont(PDF *p, const char *fontname, const char *encoding, int embed);

/* Place an image or template on the page, subject to various options. */
PDFLIB_API void PDFLIB_CALL
PDF_fit_image(PDF *p, int image, double x, double y, const char *optlist);

/* Place an imported PDF page on the output page subject to various options. */
PDFLIB_API void PDFLIB_CALL
PDF_fit_pdi_page(PDF *p, int page, double x, double y, const char *optlist);

/* Fully or partially place a table on the page.
   Returns: A string which specifies the reason for returning.
*/
PDFLIB_API const char * PDFLIB_CALL
PDF_fit_table(PDF *p, int table, double llx, double lly,
    double urx, double ury, const char *optlist);

/* Format the next portion of a Textflow.
   Returns: A string which specifies the reason for returning.
*/
PDFLIB_API const char * PDFLIB_CALL
PDF_fit_textflow(PDF *p, int textflow, double llx, double lly,
    double urx, double ury, const char *optlist);

/* Place a single line of text at position (x, y) subject to various options. */
PDFLIB_API void PDFLIB_CALL
PDF_fit_textline(PDF *p, const char *text, int len, double x, double y,
    const char *optlist);

/*
 * Retrieve a structure with PDFlib API function pointers (mainly for DLLs).
 * Although this function is published here, it is not supposed to be used
 * directly by clients. Use PDF_new_dl() in pdflibdl.c instead.
 */
PDFLIB_API const PDFlib_api * PDFLIB_CALL
PDF_get_api(void);

/* Get the name of the API function which threw the last exception or failed.
   Returns: Name of an API function.
*/
PDFLIB_API const char * PDFLIB_CALL
PDF_get_apiname(PDF *p);

/* Get the contents of the PDF output buffer.
   Returns: A buffer full of binary PDF data for consumption by the client.
*/
PDFLIB_API const char * PDFLIB_CALL
PDF_get_buffer(PDF *p, long *size);

/* Get the text of the last thrown exception or the reason of a failed
   function call.
   Returns: Text containing the description of the most recent error condition.
*/
PDFLIB_API const char * PDFLIB_CALL
PDF_get_errmsg(PDF *p);

/* Get the number of the last thrown exception or the reason of a failed
   function call.
   Returns: The error code of the most recent error condition.
*/
PDFLIB_API int PDFLIB_CALL
PDF_get_errnum(PDF *p);

/* Request the amount of kerning between two glyphs (unsupported). */
PDFLIB_API double PDFLIB_CALL
PDF_get_kern_amount(PDF *p, int font, int gidleft, int gidright);

/* Deprecated, use PDF_get_value(). */
PDFLIB_API int PDFLIB_CALL
PDF_get_majorversion(void);

/* Deprecated, use PDF_get_value(). */
PDFLIB_API int PDFLIB_CALL
PDF_get_minorversion(void);

/* Fetch the opaque application pointer stored in PDFlib.
   Returns: The opaque application pointer stored in PDFlib.
*/
PDFLIB_API void * PDFLIB_CALL
PDF_get_opaque(PDF *p);

/* Get the contents of some PDFlib parameter with string type.
   Returns: The string value of the parameter as a hypertext string.
*/
PDFLIB_API const char * PDFLIB_CALL
PDF_get_parameter(PDF *p, const char *key, double modifier);

/* Deprecated, use PDF_pcos_get_string(). */
PDFLIB_API const char *PDFLIB_CALL
PDF_get_pdi_parameter(PDF *p, const char *key, int doc, int page,
    int reserved, int *len);

/* Deprecated, use PDF_pcos_get_number. */
PDFLIB_API double PDFLIB_CALL
PDF_get_pdi_value(PDF *p, const char *key, int doc, int page, int reserved);

/* Get the value of some PDFlib parameter with numerical type.
   Returns: The numerical value of the parameter.
*/
PDFLIB_API double PDFLIB_CALL
PDF_get_value(PDF *p, const char *key, double modifier);

/* Query detailed information about a loaded font.
   Returns: The value of some font property as requested by keyword.
*/
PDFLIB_API double PDFLIB_CALL
PDF_info_font(PDF *p, int font, const char *keyword, const char *optlist);

/* Format an image and query metrics and other image properties.
   Returns: The value of some image metrics as requested by keyword.
*/
PDFLIB_API double PDFLIB_CALL
PDF_info_image(PDF *p, int image, const char *keyword, const char *optlist);

/* Query information about a matchbox on the current page.
   Returns: The value of some matchbox parameter as requested by keyword.
*/
PDFLIB_API double PDFLIB_CALL
PDF_info_matchbox(PDF *p, const char *boxname, int len, int num,
    const char *keyword);

/* Query the results of drawing a path object without actually drawing it.
   Returns: The value of some geometrical values as requested by keyword.
*/
PDFLIB_API double PDFLIB_CALL
PDF_info_path(PDF *p, int path, const char *keyword, const char *optlist);

/* Perform formatting calculations for a PDI page and query the resulting
   metrics.
   Returns: The value of some page metrics as requested by keyword.
*/
PDFLIB_API double PDFLIB_CALL
PDF_info_pdi_page(PDF *p, int page, const char *keyword, const char *optlist);

/* Query table information related to the most recently placed table
   instance.
   Returns: The value of some table parameter as requested by keyword.
*/
PDFLIB_API double PDFLIB_CALL
PDF_info_table(PDF *p, int table, const char *keyword);

/* Query the current state of a Textflow after a call to PDF_fit_textflow().
   Returns: The value of some table parameter as requested by keyword.
*/
PDFLIB_API double PDFLIB_CALL
PDF_info_textflow(PDF *p, int textflow, const char *keyword);

/* Perform textline formatting without creating output and query the resulting
   metrics.
   Returns: The value of some text metric value as requested by keyword.
*/
PDFLIB_API double PDFLIB_CALL
PDF_info_textline(PDF *p, const char *text, int len, const char *keyword,
    const char *optlist);

/* Reset all color and graphics state parameters to their default values. */
PDFLIB_API void PDFLIB_CALL
PDF_initgraphics(PDF *p);

/* Draw a line from the current point to another point. */
PDFLIB_API void PDFLIB_CALL
PDF_lineto(PDF *p, double x, double y);

/* Load a 3D model from a disk-based or virtual file (requires PDF 1.6).
   Returns: A 3D handle, or -1 (in PHP: 0) on error.
*/
PDFLIB_API int PDFLIB_CALL
PDF_load_3ddata(PDF *p, const char *filename, int len, const char *optlist);

/* Search for a font and prepare it for later use.
   Returns: A font handle.
*/
PDFLIB_API int PDFLIB_CALL
PDF_load_font(PDF *p, const char *fontname, int len,
    const char *encoding, const char *optlist);

/* Search for an ICC profile and prepare it for later use.
   Returns: A profile handle.
*/
PDFLIB_API int PDFLIB_CALL
PDF_load_iccprofile(PDF *p, const char *profilename, int len,
    const char *optlist);

/* Open a disk-based or virtual image file subject to various options.
   Returns: An image handle, or -1 (in PHP: 0) on error.
*/
PDFLIB_API int PDFLIB_CALL
PDF_load_image(PDF *p, const char *imagetype, const char *filename,
    int len, const char *optlist);

/* Find a built-in spot color name, or make a named spot color from the
   current fill color.
   Returns: A color handle.
*/
PDFLIB_API int PDFLIB_CALL
PDF_makespotcolor(PDF *p, const char *spotname, int reserved);

/* Add a marked content point with optional properties. */
PDFLIB_API void PDFLIB_CALL
PDF_mc_point(PDF *p, const char *tag, const char *optlist);

/* Set the current point for graphics output. */
PDFLIB_API void PDFLIB_CALL
PDF_moveto(PDF *p, double x, double y);

/* Create a new PDFlib object.
   Returns: A handle to a PDFlib object.
*/
PDFLIB_API PDF * PDFLIB_CALL
PDF_new(void);

/* Create a new PDFlib object with client-supplied error handling and memory
   allocation routines.
   Returns: A handle to a PDFlib object.
*/
typedef void  (*errorproc_t)(PDF *p1, int errortype, const char *msg);
typedef void* (*allocproc_t)(PDF *p2, size_t size, const char *caller);
typedef void* (*reallocproc_t)(PDF *p3,
                void *mem, size_t size, const char *caller);
typedef void  (*freeproc_t)(PDF *p4, void *mem);

PDFLIB_API PDF * PDFLIB_CALL
PDF_new2(errorproc_t errorhandler, allocproc_t allocproc,
        reallocproc_t reallocproc, freeproc_t freeproc, void *opaque);

/* Deprecated, use PDF_load_image(). */
PDFLIB_API int PDFLIB_CALL
PDF_open_CCITT(PDF *p, const char *filename, int width, int height,
    int BitReverse, int K, int BlackIs1);

/* Deprecated, use PDF_begin_document(). */
PDFLIB_API int PDFLIB_CALL
PDF_open_file(PDF *p, const char *filename);

/* Deprecated, use PDF_load_image() with virtual files. */
PDFLIB_API int PDFLIB_CALL
PDF_open_image(PDF *p, const char *imagetype, const char *source,
    const char *data, long length, int width, int height, int components,
    int bpc, const char *params);

/* Deprecated, use PDF_load_image(). */
PDFLIB_API int PDFLIB_CALL
PDF_open_image_file(PDF *p, const char *imagetype, const char *filename,
    const char *stringparam, int intparam);

/* Deprecated, use PDF_begin_document_callback(). */
PDFLIB_API void PDFLIB_CALL
PDF_open_mem(PDF *p, writeproc_t writeproc);

/* Deprecated, use PDF_open_pdi_document(). */
PDFLIB_API int PDFLIB_CALL
PDF_open_pdi(PDF *p, const char *filename, const char *optlist, int len);

/* Open a disk-based or virtual PDF document and prepare it for later use.
   Returns: A PDI document handle.
*/
PDFLIB_API int PDFLIB_CALL
PDF_open_pdi_document(PDF *p, const char *filename, int len,
    const char *optlist);

/* Open a PDF document from a custom data source and prepare it for
   later use.
   Returns: A PDI document handle.
*/
PDFLIB_API int PDFLIB_CALL
PDF_open_pdi_callback(PDF *p, void *opaque, size_t filesize,
    size_t (*readproc)(void *opaque, void *buffer, size_t size),
    int (*seekproc)(void *opaque, long offset),
    const char *optlist);

/* Prepare a page for later use with PDF_fit_pdi_page().
   Returns: A page handle.
*/
PDFLIB_API int PDFLIB_CALL
PDF_open_pdi_page(PDF *p, int doc, int pagenumber, const char *optlist);

/* Get the value of a pCOS path with type number or boolean.
   Returns: The numerical value of the object identified by the pCOS path.
*/
PDFLIB_API double PDFLIB_CALL
PDF_pcos_get_number(PDF *p, int doc, const char *path, ...);

/* Get the value of a pCOS path with type name, string or boolean.
   Returns: A string with the value of the object identified by the pCOS path.
*/
PDFLIB_API const char * PDFLIB_CALL
PDF_pcos_get_string(PDF *p, int doc, const char *path, ...);

/* Get the contents of a pCOS path with type stream, fstream, or string.
   Returns: The unencrypted data contained in the stream or string.
*/
PDFLIB_API const unsigned char * PDFLIB_CALL
PDF_pcos_get_stream(PDF *p, int doc, int *length, const char *optlist,
    const char *path, ...);

/* Deprecated, use PDF_fit_image(). */
PDFLIB_API void PDFLIB_CALL
PDF_place_image(PDF *p, int image, double x, double y, double scale);

/* Deprecated, use PDF_fit_pdi_page(). */
PDFLIB_API void PDFLIB_CALL
PDF_place_pdi_page(PDF *p, int page, double x, double y, double sx, double sy);

/* Process certain elements of an imported PDF document.
   Returns: -1 (in PHP: 0) on error, and 1 otherwise.
*/
PDFLIB_API int PDFLIB_CALL
PDF_process_pdi(PDF *p, int doc, int page, const char *optlist);

/* Draw a Bezier curve using relative coordinates (unsupported). */
PDFLIB_API void PDFLIB_CALL
PDF_rcurveto(PDF *p,
    double x_1, double y_1, double x_2, double y_2, double x_3, double y_3);

/* Draw a rectangle. */
PDFLIB_API void PDFLIB_CALL
PDF_rect(PDF *p, double x, double y, double width, double height);

/* Restore the most recently saved graphics state from the stack. */
PDFLIB_API void PDFLIB_CALL
PDF_restore(PDF *p);

/* Resume a page to add more content to it. */
PDFLIB_API void PDFLIB_CALL
PDF_resume_page(PDF *p, const char *optlist);

/* Draw a line from the current point to (cp + (x, y)) (unsupported). */
PDFLIB_API void PDFLIB_CALL
PDF_rlineto(PDF *p, double x, double y);

/* Set the new current point relative the old current point (unsupported). */
PDFLIB_API void PDFLIB_CALL
PDF_rmoveto(PDF *p, double x, double y);

/* Rotate the coordinate system. */
PDFLIB_API void PDFLIB_CALL
PDF_rotate(PDF *p, double phi);

/* Save the current graphics state to a stack. */
PDFLIB_API void PDFLIB_CALL
PDF_save(PDF *p);

/* Scale the coordinate system. */
PDFLIB_API void PDFLIB_CALL
PDF_scale(PDF *p, double sx, double sy);

/* Deprecated, use PDF_create_annotation(). */
PDFLIB_API void PDFLIB_CALL
PDF_set_border_color(PDF *p, double red, double green, double blue);

/* Deprecated, use PDF_create_annotation(). */
PDFLIB_API void PDFLIB_CALL
PDF_set_border_dash(PDF *p, double b, double w);

/* Deprecated, use PDF_create_annotation(). */
PDFLIB_API void PDFLIB_CALL
PDF_set_border_style(PDF *p, const char *style, double width);

/* Activate a graphics state object. */
PDFLIB_API void PDFLIB_CALL
PDF_set_gstate(PDF *p, int gstate);

/* Fill document information field key with value. */
PDFLIB_API void PDFLIB_CALL
PDF_set_info(PDF *p, const char *key, const char *value);

/* Like PDF_set_info(), but with explicit string length. */
PDFLIB_API void PDFLIB_CALL
PDF_set_info2(PDF *p, const char *key, const char *value, int len);

/* Define layer relationships and variants (requires PDF 1.5). */
PDFLIB_API void PDFLIB_CALL
PDF_set_layer_dependency(PDF *p, const char *type, const char *optlist);

/* Set one or more global options. */
PDFLIB_API void PDFLIB_CALL
PDF_set_option(PDF *p, const char *optlist);

/* Set some PDFlib parameter with string type. */
PDFLIB_API void PDFLIB_CALL
PDF_set_parameter(PDF *p, const char *key, const char *value);

/* Set the position for simple text output on the page. */
PDFLIB_API void PDFLIB_CALL
PDF_set_text_pos(PDF *p, double x, double y);

/* Set the value of some PDFlib parameter with numerical type. */
PDFLIB_API void PDFLIB_CALL
PDF_set_value(PDF *p, const char *key, double value);

/* Set the current color space and color. */
PDFLIB_API void PDFLIB_CALL
PDF_setcolor(PDF *p, const char *fstype, const char *colorspace,
    double c1, double c2, double c3, double c4);

/* Set the current dash pattern. */
PDFLIB_API void PDFLIB_CALL
PDF_setdash(PDF *p, double b, double w);

/* Set a dash pattern defined by an option list. */
PDFLIB_API void PDFLIB_CALL
PDF_setdashpattern(PDF *p, const char *optlist);

/* Set the flatness tolerance. */
PDFLIB_API void PDFLIB_CALL
PDF_setflat(PDF *p, double flatness);

/* Set the current font in the specified size. */
PDFLIB_API void PDFLIB_CALL
PDF_setfont(PDF *p, int font, double fontsize);

/* Deprecated, use PDF_setcolor(). */
PDFLIB_API void PDFLIB_CALL
PDF_setgray(PDF *p, double gray);

/* Deprecated, use PDF_setcolor(). */
PDFLIB_API void PDFLIB_CALL
PDF_setgray_fill(PDF *p, double gray);

/* Deprecated, use PDF_setcolor(). */
PDFLIB_API void PDFLIB_CALL
PDF_setgray_stroke(PDF *p, double gray);

/* Set the linecap parameter. */
PDFLIB_API void PDFLIB_CALL
PDF_setlinecap(PDF *p, int linecap);

/* Set the linejoin style. */
PDFLIB_API void PDFLIB_CALL
PDF_setlinejoin(PDF *p, int linejoin);

/* Set the current linewidth. */
PDFLIB_API void PDFLIB_CALL
PDF_setlinewidth(PDF *p, double width);

/* Explicitly set the current transformation matrix. */
PDFLIB_API void PDFLIB_CALL
PDF_setmatrix(PDF *p, double a, double b, double c, double d,
    double e, double f);

/* Set the miter limit. */
PDFLIB_API void PDFLIB_CALL
PDF_setmiterlimit(PDF *p, double miter);

/* Deprecated, use PDF_setdashpattern(). */
PDFLIB_API void PDFLIB_CALL
PDF_setpolydash(PDF *p, float *dasharray, int length);

/* Deprecated, use PDF_setcolor(). */
PDFLIB_API void PDFLIB_CALL
PDF_setrgbcolor(PDF *p, double red, double green, double blue);

/* Deprecated, use PDF_setcolor(). */
PDFLIB_API void PDFLIB_CALL
PDF_setrgbcolor_fill(PDF *p, double red, double green, double blue);

/* Deprecated, use PDF_setcolor(). */
PDFLIB_API void PDFLIB_CALL
PDF_setrgbcolor_stroke(PDF *p, double red, double green, double blue);

/* Define a blend from the current fill color to another color (requires
   PDF 1.4).
   Returns: A shading handle.
*/
PDFLIB_API int PDFLIB_CALL
PDF_shading(PDF *p, const char *shtype, double x_0, double y_0, double x_1,
    double y_1, double c_1, double c_2, double c_3, double c_4,
    const char *optlist);

/* Define a shading pattern using a shading object (requires PDF 1.4).
   Returns: A pattern handle.
*/
PDFLIB_API int PDFLIB_CALL
PDF_shading_pattern(PDF *p, int shading, const char *optlist);

/* Fill an area with a shading, based on a shading object (requires PDF 1.4) */
PDFLIB_API void PDFLIB_CALL
PDF_shfill(PDF *p, int shading);

/* Print text in the current font and size at the current position. */
PDFLIB_API void PDFLIB_CALL
PDF_show(PDF *p, const char *text);

/* Same as PDF_show() but with explicit string length. */
PDFLIB_API void PDFLIB_CALL
PDF_show2(PDF *p, const char *text, int len);

/* Deprecated, use PDF_fit_textline() or PDF_fit_textflow(). */
PDFLIB_API int PDFLIB_CALL
PDF_show_boxed(PDF *p, const char *text, double left, double top,
    double width, double height, const char *hmode, const char *feature);

/* Deprecated, use PDF_fit_textline() or PDF_fit_textflow(). */
PDFLIB_API int PDFLIB_CALL
PDF_show_boxed2(PDF *p, const char *text, int len, double left, double top,
    double width, double height, const char *hmode, const char *feature);

/* Print text in the current font at the specified position. */
PDFLIB_API void PDFLIB_CALL
PDF_show_xy(PDF *p, const char *text, double x, double y);

/* Same as PDF_show_xy(), but with explicit string length. */
PDFLIB_API void PDFLIB_CALL
PDF_show_xy2(PDF *p, const char *text, int len, double x, double y);

/* Deprecated, and not required. */
PDFLIB_API void PDFLIB_CALL
PDF_shutdown(void);

/* Skew the coordinate system. */
PDFLIB_API void PDFLIB_CALL
PDF_skew(PDF *p, double alpha, double beta);

/* Calculate the width of text in an arbitrary font.
   Returns: The width of text.
*/
PDFLIB_API double PDFLIB_CALL
PDF_stringwidth(PDF *p, const char *text, int font, double fontsize);

/* Same as PDF_stringwidth(), but with explicit string length. */
PDFLIB_API double PDFLIB_CALL
PDF_stringwidth2(PDF *p, const char *text, int len, int font, double fontsize);

/* Stroke the path with the current line width and current stroke color,
   and clear it. */
PDFLIB_API void PDFLIB_CALL
PDF_stroke(PDF *p);

/* Suspend the current page so that it can later be resumed. */
PDFLIB_API void PDFLIB_CALL
PDF_suspend_page(PDF *p, const char *optlist);

/* Translate the origin of the coordinate system. */
PDFLIB_API void PDFLIB_CALL
PDF_translate(PDF *p, double tx, double ty);

/* Convert a string from UTF-16 format to UTF-8.
   Returns: The converted UTF-8 string, starting with the UTF-8 BOM.
*/
PDFLIB_API const char * PDFLIB_CALL
PDF_utf16_to_utf8(PDF *p, const char *utf16string, int len, int *size);

/* Convert a string from UTF-8 format to UTF-16.
   Returns: The converted UTF-16 string.
*/
PDFLIB_API const char * PDFLIB_CALL
PDF_utf8_to_utf16(PDF *p, const char *utf8string, const char *ordering,
    int *size);

/* Convert a string from UTF-32 format to UTF-8.
   Returns: The converted UTF-8 string, starting with the UTF-8 BOM.
*/
PDFLIB_API const char * PDFLIB_CALL
PDF_utf32_to_utf8(PDF *p, const char *utf32string, int len, int *size);

/* Convert a string from UTF-8 format to UTF-32.
   Returns: The converted UTF-32 string.
*/
PDFLIB_API const char * PDFLIB_CALL
PDF_utf8_to_utf32(PDF *p, const char *utf8string, const char *ordering,
    int *size);

/* Convert a string from UTF-16 format to UTF-32.
   Returns: The converted UTF-32 string.
*/
PDFLIB_API const char * PDFLIB_CALL
PDF_utf16_to_utf32(PDF *p, const char *utf16string, int len,
    const char *ordering, int *size);

/* Convert a string from UTF-32 format to UTF-16.
   Returns: The converted UTF-16 string.
*/
PDFLIB_API const char * PDFLIB_CALL
PDF_utf32_to_utf16(PDF *p, const char *utf32string, int len,
    const char *ordering, int *size);

/* Print text in the current font and size, using individual horizontal
   positions (unsupported).
*/
PDFLIB_API void PDFLIB_CALL
PDF_xshow(PDF *p, const char *text, int len, const double *xadvancelist);


/*
 * ----------------------------------------------------------------------
 * PDFlib API structure with function pointers to all API functions
 * ----------------------------------------------------------------------
 */

/* Auxiliary structure for try/catch */
typedef struct
{
    jmp_buf	jbuf;
} pdf_jmpbuf;


/* The API structure with pointers to all PDFlib API functions */
struct PDFlib_api_s {
    /* version numbers for checking the DLL against client code */
    size_t sizeof_PDFlib_api;	/* size of this structure */

    int major;			/* PDFlib major version number */
    int minor;			/* PDFlib minor version number */
    int revision;		/* PDFlib revision number */

    int reserved;		/* reserved */

    void (PDFLIB_CALL * PDF_activate_item)(PDF *p, int id);
    int (PDFLIB_CALL * PDF_add_bookmark)(PDF *p, const char *text,
                int parent, int open);
    int (PDFLIB_CALL * PDF_add_bookmark2)(PDF *p, const char *text, int len,
	        int parent, int open);
    void (PDFLIB_CALL * PDF_add_launchlink)(PDF *p,
                double llx, double lly, double urx,
                double ury, const char *filename);
    void (PDFLIB_CALL * PDF_add_locallink)(PDF *p,
                double llx, double lly, double urx,
                double ury, int page, const char *optlist);
    void (PDFLIB_CALL * PDF_add_nameddest)(PDF *p, const char *name,
	        int len, const char *optlist);
    void (PDFLIB_CALL * PDF_add_note)(PDF *p, double llx, double lly,
                double urx, double ury, const char *contents, const char *title,
		const char *icon, int open);
    void (PDFLIB_CALL * PDF_add_note2)(PDF *p, double llx, double lly,
                double urx, double ury, const char *contents, int len_cont,
		const char *title, int len_title, const char *icon, int open);
    int (PDFLIB_CALL * PDF_add_path_point)(PDF *p, int path, double x,
                double y, const char *type, const char *optlist);
    void (PDFLIB_CALL * PDF_add_pdflink)(PDF *p,
                double llx, double lly, double urx, double ury,
		const char *filename, int page, const char *optlist);
    int (PDFLIB_CALL * PDF_add_portfolio_file)(PDF *p, int folder,
                const char *filename, int len, const char *optlist);
    int (PDFLIB_CALL * PDF_add_portfolio_folder)(PDF *p, int folder,
                const char *foldername, int len, const char *optlist);
    int (PDFLIB_CALL * PDF_add_table_cell)(PDF *p, int table, int column,
                int row, const char *text, int len, const char *optlist);
    int (PDFLIB_CALL * PDF_add_textflow)(PDF *p, int textflow, const char *text,
                int len, const char *optlist);
    void (PDFLIB_CALL * PDF_add_thumbnail)(PDF *p, int image);
    void (PDFLIB_CALL * PDF_add_weblink)(PDF *p, double llx,
		double lly, double urx, double ury, const char *url);
    void (PDFLIB_CALL * PDF_align)(PDF *p, double dx, double dy);
    void (PDFLIB_CALL * PDF_arc)(PDF *p, double x, double y,
                double r, double alpha, double beta);
    void (PDFLIB_CALL * PDF_arcn)(PDF *p, double x, double y,
                double r, double alpha, double beta);
    void (PDFLIB_CALL * PDF_attach_file)(PDF *p, double llx, double lly,
                double urx, double ury, const char *filename,
		const char *description,
		const char *author, const char *mimetype, const char *icon);
    void (PDFLIB_CALL * PDF_attach_file2)(PDF *p, double llx, double lly,
                double urx, double ury, const char *filename, int len_filename,
		const char *description, int len_descr, const char *author,
		int len_auth, const char *mimetype, const char *icon);
    int (PDFLIB_CALL * PDF_begin_document)(PDF *p, const char *filename,
                int len, const char *optlist);
    void (PDFLIB_CALL * PDF_begin_document_callback)(PDF *p,
                writeproc_t writeproc, const char *optlist);
    void (PDFLIB_CALL * PDF_begin_font)(PDF *p, const char *fontname,
                int len, double a, double b, double c, double d, double e,
                double f, const char *optlist);
    void (PDFLIB_CALL * PDF_begin_glyph)(PDF *p, const char *glyphname,
                double wx, double llx, double lly, double urx, double ury);
    int (PDFLIB_CALL * PDF_begin_item)(PDF *p, const char *tag,
                const char *optlist);
    void (PDFLIB_CALL * PDF_begin_layer)(PDF *p, int layer);
    void (PDFLIB_CALL * PDF_begin_mc)(PDF *p,
		const char *tag, const char *optlist);
    void (PDFLIB_CALL * PDF_begin_page)(PDF *p, double width, double height);
    void (PDFLIB_CALL * PDF_begin_page_ext)(PDF *p, double width,
                double height, const char *optlist);
    int (PDFLIB_CALL * PDF_begin_pattern)(PDF *p, double width, double height,
                double xstep, double ystep, int painttype);
    int (PDFLIB_CALL * PDF_begin_template)(PDF *p,
                double width, double height);
    int (PDFLIB_CALL * PDF_begin_template_ext)(PDF *p,
                double width, double height, const char *optlist);
    void (PDFLIB_CALL * PDF_boot)(void);
    int (PDFLIB_CALL * PDF_check_context)(PDF *p);
    void (PDFLIB_CALL * PDF_circle)(PDF *p, double x, double y, double r);
    void (PDFLIB_CALL * PDF_circular_arc)(PDF *p, double x_1, double y_1,
                double x_2, double y_2);
    void (PDFLIB_CALL * PDF_clip)(PDF *p);
    void (PDFLIB_CALL * PDF_close)(PDF *p);
    void (PDFLIB_CALL * PDF_close_font)(PDF *p, int font);
    void (PDFLIB_CALL * PDF_close_image)(PDF *p, int image);
    void (PDFLIB_CALL * PDF_close_pdi)(PDF *p, int doc);
    void (PDFLIB_CALL * PDF_close_pdi_document)(PDF *p, int doc);
    void (PDFLIB_CALL * PDF_close_pdi_page)(PDF *p, int page);
    void (PDFLIB_CALL * PDF_closepath)(PDF *p);
    void (PDFLIB_CALL * PDF_closepath_fill_stroke)(PDF *p);
    void (PDFLIB_CALL * PDF_closepath_stroke)(PDF *p);
    void (PDFLIB_CALL * PDF_concat)(PDF *p, double a, double b,
                double c, double d, double e, double f);
    void (PDFLIB_CALL * PDF_continue_text)(PDF *p, const char *text);
    void (PDFLIB_CALL * PDF_continue_text2)(PDF *p, const char *text, int len);
    int (PDFLIB_CALL * PDF_create_3dview)(PDF *p, const char *username,
                int len, const char *optlist);
    int (PDFLIB_CALL * PDF_create_action)(PDF *p, const char *type,
                const char *optlist);
    void (PDFLIB_CALL * PDF_create_annotation)(PDF *p,
                double llx, double lly, double urx, double ury,
                const char *type, const char *optlist);
    int (PDFLIB_CALL * PDF_create_bookmark)(PDF *p, const char *text, int len,
                const char *optlist);
    void (PDFLIB_CALL * PDF_create_field)(PDF *p, double llx, double lly,
                double urx, double ury, const char *name, int len,
                const char *type, const char *optlist);
    void (PDFLIB_CALL * PDF_create_fieldgroup)(PDF *p, const char *name,
                int len, const char *optlist);
    int (PDFLIB_CALL * PDF_create_gstate)(PDF *p, const char *optlist);
    void (PDFLIB_CALL * PDF_create_pvf)(PDF *p, const char *filename,
                int len, const void *data, size_t size, const char *optlist);
    int (PDFLIB_CALL * PDF_create_textflow)(PDF *p, const char *text, int len,
                const char *optlist);
    void (PDFLIB_CALL * PDF_curveto)(PDF *p, double x_1, double y_1,
                double x_2, double y_2, double x_3, double y_3);
    int (PDFLIB_CALL * PDF_define_layer)(PDF *p, const char *name, int len,
                const char *optlist);
    const char * (PDFLIB_CALL * PDF_deflate_unicode)(PDF *p,
                const char *utfstring, int len, int charsize, int *highchar);
    void (PDFLIB_CALL * PDF_delete)(PDF *);
    void (PDFLIB_CALL * PDF_delete_path)(PDF *p, int path);
    int (PDFLIB_CALL * PDF_delete_pvf)(PDF *p, const char *filename, int len);
    void (PDFLIB_CALL * PDF_delete_table)(PDF *p, int table,
                const char *optlist);
    void (PDFLIB_CALL * PDF_delete_textflow)(PDF *p, int textflow);
    void (PDFLIB_CALL * PDF_draw_path)(PDF *p, int path, double x, double y,
                const char *optlist);
    void (PDFLIB_CALL * PDF_ellipse)(PDF *p, double x, double y,
                double rx, double ry);
    void (PDFLIB_CALL * PDF_encoding_set_char)(PDF *p, const char *encoding,
                int slot, const char *glyphname, int uv);
    void (PDFLIB_CALL * PDF_end_document)(PDF *p, const char *optlist);
    void (PDFLIB_CALL * PDF_end_font)(PDF *p);
    void (PDFLIB_CALL * PDF_end_glyph)(PDF *p);
    void (PDFLIB_CALL * PDF_end_item)(PDF *p, int id);
    void (PDFLIB_CALL * PDF_end_layer)(PDF *p);
    void (PDFLIB_CALL * PDF_end_mc)(PDF *p);
    void (PDFLIB_CALL * PDF_end_page)(PDF *p);
    void (PDFLIB_CALL * PDF_end_page_ext)(PDF *p, const char *optlist);
    void (PDFLIB_CALL * PDF_end_pattern)(PDF *p);
    void (PDFLIB_CALL * PDF_end_template)(PDF *p);
    void (PDFLIB_CALL * PDF_end_template_ext)(PDF *p,
                double width, double height);
    void (PDFLIB_CALL * PDF_endpath)(PDF *p);
    void (PDFLIB_CALL * PDF_fill)(PDF *p);
    int (PDFLIB_CALL * PDF_fill_imageblock)(PDF *p, int page,
		const char *blockname, int image, const char *optlist);
    int (PDFLIB_CALL * PDF_fill_pdfblock)(PDF *p, int page,
	        const char *blockname, int contents, const char *optlist);
    void (PDFLIB_CALL * PDF_fill_stroke)(PDF *p);
    int (PDFLIB_CALL * PDF_fill_textblock)(PDF *p, int page,
	        const char *blockname, const char *text, int len,
	        const char *optlist);
    int (PDFLIB_CALL * PDF_findfont)(PDF *p, const char *fontname,
	        const char *encoding, int embed);
    void (PDFLIB_CALL * PDF_fit_image)(PDF *p, int image, double x, double y,
	        const char *optlist);
    void (PDFLIB_CALL * PDF_fit_pdi_page)(PDF *p, int page, double x,
                double y, const char *optlist);
    const char * (PDFLIB_CALL * PDF_fit_table)(PDF *p, int table,
                double llx, double lly, double urx, double ury,
                const char *optlist);
    const char * (PDFLIB_CALL * PDF_fit_textflow)(PDF *p, int textflow,
                double llx, double lly, double urx, double ury,
                const char *optlist);
    void (PDFLIB_CALL * PDF_fit_textline)(PDF *p, const char *text,
                int len, double x, double y, const char *optlist);
    const PDFlib_api * (PDFLIB_CALL * PDF_get_api)(void);
    const char * (PDFLIB_CALL * PDF_get_apiname)(PDF *p);
    const char * (PDFLIB_CALL * PDF_get_buffer)(PDF *p, long *size);
    const char * (PDFLIB_CALL * PDF_get_errmsg)(PDF *p);
    int (PDFLIB_CALL * PDF_get_errnum)(PDF *p);
    int (PDFLIB_CALL * PDF_get_minorversion)(void);
    int (PDFLIB_CALL * PDF_get_majorversion)(void);
    void * (PDFLIB_CALL * PDF_get_opaque)(PDF *p);
    const char * (PDFLIB_CALL * PDF_get_parameter)(PDF *p,
                const char *key, double modifier);
    const char * (PDFLIB_CALL * PDF_get_pdi_parameter)(PDF *p,
		const char *key, int doc, int page, int reserved, int *len);
    double (PDFLIB_CALL * PDF_get_pdi_value)(PDF *p, const char *key,
                int doc, int page, int reserved);
    double (PDFLIB_CALL * PDF_get_value)(PDF *p, const char *key,
                double modifier);
    double (PDFLIB_CALL * PDF_info_font)(PDF *p, int font, const char *keyword,
                const char *optlist);
    double (PDFLIB_CALL *PDF_info_image)(PDF *p, int image, const char *keyword,
                const char *optlist);
    double (PDFLIB_CALL * PDF_info_matchbox)(PDF *p, const char *boxname,
                int len, int num, const char *keyword);
    double (PDFLIB_CALL * PDF_info_path)(PDF *p, int path, const char *keyword,
                const char *optlist);
    double (PDFLIB_CALL * PDF_info_pdi_page)(PDF *p, int page,
                const char *keyword, const char *optlist);
    double (PDFLIB_CALL * PDF_info_table)(PDF *p, int table,
                const char *keyword);
    double (PDFLIB_CALL * PDF_info_textflow)(PDF *p, int textflow,
                const char *keyword);
    double (PDFLIB_CALL * PDF_info_textline)(PDF *p, const char *text, int len,
                const char *keyword, const char *optlist);
    void (PDFLIB_CALL * PDF_initgraphics)(PDF *p);
    void (PDFLIB_CALL * PDF_lineto)(PDF *p, double x, double y);
    int (PDFLIB_CALL * PDF_load_3ddata)(PDF *p, const char *filename, int len,
                const char *optlist);
    int (PDFLIB_CALL * PDF_load_font)(PDF *p, const char *fontname,
		int len, const char *encoding, const char *optlist);
    int (PDFLIB_CALL * PDF_load_iccprofile)(PDF *p, const char *profilename,
                int len, const char *optlist);
    int (PDFLIB_CALL * PDF_load_image)(PDF *p, const char *imagetype,
	        const char *filename, int len, const char *optlist);
    int (PDFLIB_CALL * PDF_makespotcolor)(PDF *p, const char *spotname,
                int len);
    void (PDFLIB_CALL * PDF_mc_point)(PDF *p,
    	        const char *tag, const char *optlist);
    void (PDFLIB_CALL * PDF_moveto)(PDF *p, double x, double y);
    PDF* (PDFLIB_CALL * PDF_new)(void);
    PDF* (PDFLIB_CALL * PDF_new2)(errorproc_t errorhandler,
                allocproc_t allocproc, reallocproc_t reallocproc,
                freeproc_t freeproc, void *opaque);
    int (PDFLIB_CALL * PDF_open_CCITT)(PDF *p, const char *filename,
    	        int width, int height, int BitReverse, int K, int BlackIs1);
    int (PDFLIB_CALL * PDF_open_file)(PDF *p, const char *filename);
    int (PDFLIB_CALL * PDF_open_image)(PDF *p, const char *imagetype,
		const char *source, const char *data, long length, int width,
		int height, int components, int bpc, const char *params);
    int (PDFLIB_CALL * PDF_open_image_file)(PDF *p, const char *imagetype,
		const char *filename, const char *stringparam, int intparam);
    void (PDFLIB_CALL * PDF_open_mem)(PDF *p, writeproc_t writeproc);
    int (PDFLIB_CALL * PDF_open_pdi)(PDF *p, const char *filename,
                const char *optlist, int len);
    int (PDFLIB_CALL * PDF_open_pdi_callback)(PDF *p, void *opaque,
	    size_t filesize, size_t (*readproc)(void *opaque, void *buffer,
	    size_t size), int (*seekproc)(void *opaque, long offset),
	    const char *optlist);
    int (PDFLIB_CALL * PDF_open_pdi_document)(PDF *p, const char *filename,
                int len, const char *optlist);
    int (PDFLIB_CALL * PDF_open_pdi_page)(PDF *p,
	        int doc, int pagenumber, const char *optlist);
    double (PDFLIB_CALL * PDF_pcos_get_number)(PDF *p,
		int doc, const char *path, ...);
    const unsigned char * (PDFLIB_CALL * PDF_pcos_get_stream)(PDF *p,
		int doc, int *length, const char *optlist,
		const char *path, ...);
    const char * (PDFLIB_CALL * PDF_pcos_get_string)(PDF *p,
                int doc, const char *path, ...);
    void (PDFLIB_CALL * PDF_place_image)(PDF *p, int image,
                double x, double y, double scale);
    void (PDFLIB_CALL * PDF_place_pdi_page)(PDF *p, int page,
                double x, double y, double sx, double sy);
    int (PDFLIB_CALL * PDF_process_pdi)(PDF *p, int doc, int page,
                const char *optlist);
    void (PDFLIB_CALL * PDF_rect)(PDF *p, double x, double y,
                double width, double height);
    void (PDFLIB_CALL * PDF_restore)(PDF *p);
    void (PDFLIB_CALL * PDF_resume_page)(PDF *p, const char *optlist);
    void (PDFLIB_CALL * PDF_rotate)(PDF *p, double phi);
    void (PDFLIB_CALL * PDF_save)(PDF *p);
    void (PDFLIB_CALL * PDF_scale)(PDF *p, double sx, double sy);
    void (PDFLIB_CALL * PDF_set_border_color)(PDF *p,
                double red, double green, double blue);
    void (PDFLIB_CALL * PDF_set_border_dash)(PDF *p, double b, double w);
    void (PDFLIB_CALL * PDF_set_border_style)(PDF *p,
                const char *style, double width);
    void (PDFLIB_CALL * PDF_set_gstate)(PDF *p, int gstate);
    void (PDFLIB_CALL * PDF_set_info)(PDF *p, const char *key,
	        const char *value);
    void (PDFLIB_CALL * PDF_set_info2)(PDF *p, const char *key,
	        const char *value, int len);
    void (PDFLIB_CALL * PDF_set_layer_dependency)(PDF *p, const char *type,
                const char *optlist);
    void (PDFLIB_CALL * PDF_set_option)(PDF *p, const char *optlist);
    void (PDFLIB_CALL * PDF_set_parameter)(PDF *p, const char *key,
                const char *value);
    void (PDFLIB_CALL * PDF_set_text_pos)(PDF *p, double x, double y);
    void (PDFLIB_CALL * PDF_set_value)(PDF *p, const char *key, double value);
    void (PDFLIB_CALL * PDF_setcolor)(PDF *p, const char *fstype,
                const char *colorspace, double c1, double c2,
                double c3, double c4);
    void (PDFLIB_CALL * PDF_setdash)(PDF *p, double b, double w);
    void (PDFLIB_CALL * PDF_setdashpattern)(PDF *p, const char *optlist);
    void (PDFLIB_CALL * PDF_setflat)(PDF *p, double flatness);
    void (PDFLIB_CALL * PDF_setfont)(PDF *p, int font, double fontsize);
    void (PDFLIB_CALL * PDF_setgray)(PDF *p, double gray);
    void (PDFLIB_CALL * PDF_setgray_fill)(PDF *p, double gray);
    void (PDFLIB_CALL * PDF_setgray_stroke)(PDF *p, double gray);
    void (PDFLIB_CALL * PDF_setlinecap)(PDF *p, int linecap);
    void (PDFLIB_CALL * PDF_setlinejoin)(PDF *p, int linejoin);
    void (PDFLIB_CALL * PDF_setlinewidth)(PDF *p, double width);
    void (PDFLIB_CALL * PDF_setmatrix)(PDF *p, double a, double b,
                double c, double d, double e, double f);
    void (PDFLIB_CALL * PDF_setmiterlimit)(PDF *p, double miter);
    void (PDFLIB_CALL * PDF_setpolydash)(PDF *p, float *dasharray, int length);
    void (PDFLIB_CALL * PDF_setrgbcolor)(PDF *p, double red, double green,
                double blue);
    void (PDFLIB_CALL * PDF_setrgbcolor_fill)(PDF *p,
                double red, double green, double blue);
    void (PDFLIB_CALL * PDF_setrgbcolor_stroke)(PDF *p,
                double red, double green, double blue);
    int (PDFLIB_CALL * PDF_shading)(PDF *p, const char *shtype, double x_0,
                double y_0, double x_1, double y_1, double c_1, double c_2,
                double c_3, double c_4, const char *optlist);
    int (PDFLIB_CALL * PDF_shading_pattern)(PDF *p, int shading,
                const char *optlist);
    void (PDFLIB_CALL * PDF_shfill)(PDF *p, int shading);
    void (PDFLIB_CALL * PDF_show)(PDF *p, const char *text);
    void (PDFLIB_CALL * PDF_show2)(PDF *p, const char *text, int len);
    int (PDFLIB_CALL * PDF_show_boxed)(PDF *p, const char *text,
                double left, double top, double width, double height,
                const char *hmode, const char *feature);
    int (PDFLIB_CALL * PDF_show_boxed2)(PDF *p, const char *text, int len,
                double left, double top, double width, double height,
                const char *hmode, const char *feature);
    void (PDFLIB_CALL * PDF_show_xy)(PDF *p, const char *text, double x,
                double y);
    void (PDFLIB_CALL * PDF_show_xy2)(PDF *p, const char *text,
                int len, double x, double y);
    void (PDFLIB_CALL * PDF_shutdown)(void);
    void (PDFLIB_CALL * PDF_skew)(PDF *p, double alpha, double beta);
    double (PDFLIB_CALL * PDF_stringwidth)(PDF *p, const char *text,
                int font, double fontsize);
    double (PDFLIB_CALL * PDF_stringwidth2)(PDF *p, const char *text,
                int len, int font, double fontsize);
    void (PDFLIB_CALL * PDF_stroke)(PDF *p);
    void (PDFLIB_CALL * PDF_suspend_page)(PDF *p, const char *optlist);
    void (PDFLIB_CALL * PDF_translate)(PDF *p, double tx, double ty);
    const char * (PDFLIB_CALL * PDF_utf16_to_utf8)(PDF *p,
                const char *utf16string, int len, int *size);
    const char * (PDFLIB_CALL * PDF_utf8_to_utf16)(PDF *p,
                const char *utf8string, const char *ordering, int *size);
    const char * (PDFLIB_CALL * PDF_utf32_to_utf8)(PDF *p,
                const char *utf32string, int len, int *size);
    const char * (PDFLIB_CALL * PDF_utf8_to_utf32)(PDF *p,
                const char *utf8string, const char *ordering, int *size);
    const char * (PDFLIB_CALL * PDF_utf16_to_utf32)(PDF *p,
                const char *utf16string, int len, const char *ordering,
                int *size);
    const char * (PDFLIB_CALL * PDF_utf32_to_utf16)(PDF *p,
                const char *utf32string, int len, const char *ordering,
                int *size);
    void (PDFLIB_CALL * PDF_xshow)(PDF *p, const char *text, int len,
                const double *xadvancelist);

    int (PDFLIB_CALL * pdf_catch)(PDF *p);
    void (PDFLIB_CALL * pdf_exit_try)(PDF *p);
    pdf_jmpbuf * (PDFLIB_CALL * pdf_jbuf)(PDF *p);
    void (PDFLIB_CALL * pdf_rethrow)(PDF *p);
};


/*
 * ----------------------------------------------------------------------
 * pCOS-specific enums and defines
 * ----------------------------------------------------------------------
 */

/*
 * Guard against multiple definition of pcos_mode and pcos_object_type for the
 * case that multiple PDFlib products are used in the same program.
 */

#ifndef PDF_PCOS_ENUMS

/* document access levels.
*/
typedef enum
{
    pcos_mode_minimum	 = 0, /* encrypted doc (opened w/o password)	      */
    pcos_mode_restricted = 1, /* encrypted doc (opened w/ user password)      */
    pcos_mode_full	 = 2  /* unencrypted doc or opened w/ master password */
} pcos_mode;


/* object types.
*/
typedef enum
{
    pcos_ot_null	= 0,
    pcos_ot_boolean	= 1,
    pcos_ot_number	= 2,
    pcos_ot_name	= 3,
    pcos_ot_string	= 4,
    pcos_ot_array	= 5,
    pcos_ot_dict	= 6,
    pcos_ot_stream	= 7,
    pcos_ot_fstream	= 8
} pcos_object_type;

#define PDF_PCOS_ENUMS

#endif /* PDF_PCOS_ENUMS */


/*
 * ----------------------------------------------------------------------
 * Exception handling with try/catch implementation
 * ----------------------------------------------------------------------
 */

/* Set up an exception handling frame; must always be paired with PDF_CATCH().*/

#define PDF_TRY(p)		if (p) { if (setjmp(pdf_jbuf(p)->jbuf) == 0)

/* Inform the exception machinery that a PDF_TRY() will be left without
   entering the corresponding PDF_CATCH( ) clause. */
#define PDF_EXIT_TRY(p)		pdf_exit_try(p)

/* Catch an exception; must always be paired with PDF_TRY(). */
#define PDF_CATCH(p)		} if (pdf_catch(p))

/* Re-throw an exception to another handler. */
#define PDF_RETHROW(p)		pdf_rethrow(p)


/*
 * ----------------------------------------------------------------------
 * End of supported public declarations
 * ----------------------------------------------------------------------
 */

/*
 * ------------------------------------------------------------------------
 * Deprecated: macros for page size formats
 * ------------------------------------------------------------------------
 */

/*
 * The page sizes are only available to the C and C++ bindings.
 * These are deprecated; corresponding options are supported in
 * PDF_begin_page_ext().
 */

#define a0_width	 2380.0
#define a0_height	 3368.0
#define a1_width	 1684.0
#define a1_height	 2380.0
#define a2_width	 1190.0
#define a2_height	 1684.0
#define a3_width	 842.0
#define a3_height	 1190.0
#define a4_width	 595.0
#define a4_height	 842.0
#define a5_width	 421.0
#define a5_height	 595.0
#define a6_width	 297.0
#define a6_height	 421.0
#define b5_width	 501.0
#define b5_height	 709.0
#define letter_width	 612.0
#define letter_height	 792.0
#define legal_width 	 612.0
#define legal_height 	 1008.0
#define ledger_width	 1224.0
#define ledger_height	 792.0
#define p11x17_width	 792.0
#define p11x17_height	 1224.0


/*
 * ----------------------------------------------------------------------
 * Deprecated: Error classes
 * Old-style error handlers are still supported, but
 * they will always receive PDF_UnknownError.
 * ----------------------------------------------------------------------
 */

#define PDF_UnknownError  12


/*
 * ----------------------------------------------------------------------
 * Deprecated functions (should no longer be used)
 * ----------------------------------------------------------------------
 */

#if _MSC_VER >= 1310    /* VS .NET 2003 and later */
#pragma deprecated(PDF_add_bookmark)
#pragma deprecated(PDF_add_bookmark2)
#pragma deprecated(PDF_add_launchlink)
#pragma deprecated(PDF_add_locallink)
#pragma deprecated(PDF_add_note)
#pragma deprecated(PDF_add_note2)
#pragma deprecated(PDF_add_pdflink)
#pragma deprecated(PDF_add_weblink)
#pragma deprecated(PDF_attach_file)
#pragma deprecated(PDF_attach_file2)
#pragma deprecated(PDF_begin_page)
#pragma deprecated(PDF_begin_template)
#pragma deprecated(PDF_boot)
#pragma deprecated(PDF_close)
#pragma deprecated(PDF_close_pdi)
#pragma deprecated(PDF_end_page)
#pragma deprecated(PDF_end_template)
#pragma deprecated(PDF_findfont)
#pragma deprecated(PDF_get_majorversion)
#pragma deprecated(PDF_get_minorversion)
#pragma deprecated(PDF_get_pdi_value)
#pragma deprecated(PDF_get_pdi_parameter)
#pragma deprecated(PDF_open_CCITT)
#pragma deprecated(PDF_open_file)
#pragma deprecated(PDF_open_image)
#pragma deprecated(PDF_open_image_file)
#pragma deprecated(PDF_open_mem)
#pragma deprecated(PDF_open_pdi)
#pragma deprecated(PDF_place_image)
#pragma deprecated(PDF_place_pdi_page)
#pragma deprecated(PDF_set_border_color)
#pragma deprecated(PDF_set_border_dash)
#pragma deprecated(PDF_set_border_style)
#pragma deprecated(PDF_setgray)
#pragma deprecated(PDF_setgray_fill)
#pragma deprecated(PDF_setgray_stroke)
#pragma deprecated(PDF_setpolydash)
#pragma deprecated(PDF_setrgbcolor)
#pragma deprecated(PDF_setrgbcolor_fill)
#pragma deprecated(PDF_setrgbcolor_stroke)
#pragma deprecated(PDF_show_boxed)
#pragma deprecated(PDF_show_boxed2)
#pragma deprecated(PDF_shutdown)
#endif

/*
 * ----------------------------------------------------------------------
 * Private stuff, do not use explicitly but only via the macros above!
 * ----------------------------------------------------------------------
 */

PDFLIB_API pdf_jmpbuf * PDFLIB_CALL
pdf_jbuf(PDF *p);

PDFLIB_API void PDFLIB_CALL
pdf_exit_try(PDF *p);

PDFLIB_API int PDFLIB_CALL
pdf_catch(PDF *p);

PDFLIB_API void PDFLIB_CALL
pdf_rethrow(PDF *p);

PDFLIB_API void PDFLIB_CALL
pdf_throw(PDF *p, const char *binding, const char *apiname, const char *errmsg);


/*
 * ----------------------------------------------------------------------
 * End of useful stuff
 * ----------------------------------------------------------------------
 */

#ifdef __cplusplus
}	/* extern "C" */
#endif

#endif	/* PDFLIB_H */

/*
 * vim600: sw=4 fdm=marker
 */

