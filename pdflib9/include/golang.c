#include <stdio.h>
#include "pdflib.h"

void _PDF_activate_item(PDF *p, int id) {
	PDF_TRY(p) { PDF_activate_item(p, id); } PDF_CATCH(p) { }
}

void _PDF_add_nameddest(PDF *p, const char *name, int len, const char *optlist) {
	PDF_TRY(p) { PDF_add_nameddest(p, name, len, optlist); } PDF_CATCH(p) { }
}

int _PDF_add_path_point(PDF *p, int path, double x, double y, const char *type, const char *optlist) {
	PDF_TRY(p) { return PDF_add_path_point(p, path, x, y, type, optlist); } PDF_CATCH(p) { } return -1;
}

int _PDF_add_portfolio_file(PDF *p, int folder, const char *filename, int len, const char *optlist) {
	PDF_TRY(p) { return PDF_add_portfolio_file(p, folder, filename, len, optlist); } PDF_CATCH(p) { } return -1;
}

int _PDF_add_portfolio_folder(PDF *p, int parent, const char *foldername, int len, const char *optlist) {
	PDF_TRY(p) { return PDF_add_portfolio_folder(p, parent, foldername, len, optlist); } PDF_CATCH(p) { } return -1;
}

int _PDF_add_table_cell(PDF *p, int table, int column, int row, const char *text, int len, const char *optlist) {
	PDF_TRY(p) { return PDF_add_table_cell(p, table, column, row, text, len, optlist); } PDF_CATCH(p) { } return -1;
}

int _PDF_add_textflow(PDF *p, int textflow, const char *text, int len, const char *optlist) {
	PDF_TRY(p) { return PDF_add_textflow(p, textflow, text, len, optlist); } PDF_CATCH(p) { } return -1;
}

void _PDF_add_thumbnail(PDF *p, int image) {
	PDF_TRY(p) { PDF_add_thumbnail(p, image); } PDF_CATCH(p) { }
}

void _PDF_align(PDF *p, double dx, double dy) {
	PDF_TRY(p) { PDF_align(p, dx, dy); } PDF_CATCH(p) { }
}

void _PDF_arc(PDF *p, double x, double y, double r, double alpha, double beta) {
	PDF_TRY(p) { PDF_arc(p, x, y, r, alpha, beta); } PDF_CATCH(p) { }
}

void _PDF_arcn(PDF *p, double x, double y, double r, double alpha, double beta) {
	PDF_TRY(p) { PDF_arcn(p, x, y, r, alpha, beta); } PDF_CATCH(p) { }
}

int _PDF_begin_document(PDF *p, const char *filename, int len, const char *optlist) {
	PDF_TRY(p) { return PDF_begin_document(p, filename, len, optlist); } PDF_CATCH(p) { } return -1;
}

void _PDF_begin_font(PDF *p, const char *fontname, int len, double a, double b, double c, double d, double e, double f, const char *optlist) {
	PDF_TRY(p) { PDF_begin_font(p, fontname, len, a, b, c, d, e, f, optlist); } PDF_CATCH(p) { }
}

void _PDF_begin_glyph(PDF *p, const char *glyphname, double wx, double llx, double lly, double urx, double ury) {
	PDF_TRY(p) { PDF_begin_glyph(p, glyphname, wx, llx, lly, urx, ury); } PDF_CATCH(p) { }
}

int _PDF_begin_item(PDF *p, const char *tag, const char *optlist) {
	PDF_TRY(p) { return PDF_begin_item(p, tag, optlist); } PDF_CATCH(p) { } return -1;
}

void _PDF_begin_layer(PDF *p, int layer) {
	PDF_TRY(p) { PDF_begin_layer(p, layer); } PDF_CATCH(p) { }
}

void _PDF_begin_mc(PDF *p, const char *tag, const char *optlist) {
	PDF_TRY(p) { PDF_begin_mc(p, tag, optlist); } PDF_CATCH(p) { }
}

void _PDF_begin_page_ext(PDF *p, double width, double height, const char *optlist) {
	PDF_TRY(p) { PDF_begin_page_ext(p, width, height, optlist); } PDF_CATCH(p) { }
}

int _PDF_begin_pattern(PDF *p, double width, double height, double xstep, double ystep, int painttype) {
	PDF_TRY(p) { return PDF_begin_pattern(p, width, height, xstep, ystep, painttype); } PDF_CATCH(p) { } return 1;
}

int _PDF_begin_template_ext(PDF *p, double width, double height, const char *optlist) {
	PDF_TRY(p) { return PDF_begin_template_ext(p, width, height, optlist); } PDF_CATCH(p) { } return 1;
}

void _PDF_circle(PDF *p, double x, double y, double r) {
	PDF_TRY(p) { PDF_circle(p, x, y, r); } PDF_CATCH(p) { }
}

void _PDF_circular_arc(PDF *p, double x_1, double y_1, double x_2, double y_2) {
	PDF_TRY(p) { PDF_circular_arc(p, x_1, y_1, x_2, y_2); } PDF_CATCH(p) { }
}

void _PDF_clip(PDF *p) {
	PDF_TRY(p) { PDF_clip(p); } PDF_CATCH(p) { }
}

void _PDF_close_font(PDF *p, int font) {
	PDF_TRY(p) { PDF_close_font(p, font); } PDF_CATCH(p) { }
}

void _PDF_close_graphics(PDF *p, int graphics) {
	PDF_TRY(p) { PDF_close_graphics(p, graphics); } PDF_CATCH(p) { }
}

void _PDF_close_image(PDF *p, int image) {
	PDF_TRY(p) { PDF_close_image(p, image); } PDF_CATCH(p) { }
}

void _PDF_close_pdi_document(PDF *p, int doc) {
	PDF_TRY(p) { PDF_close_pdi_document(p, doc); } PDF_CATCH(p) { }
}

void _PDF_close_pdi_page(PDF *p, int page) {
	PDF_TRY(p) { PDF_close_pdi_page(p, page); } PDF_CATCH(p) { }
}

void _PDF_closepath(PDF *p) {
	PDF_TRY(p) { PDF_closepath(p); } PDF_CATCH(p) { }
}

void _PDF_closepath_fill_stroke(PDF *p) {
	PDF_TRY(p) { PDF_closepath_fill_stroke(p); } PDF_CATCH(p) { }
}

void _PDF_closepath_stroke(PDF *p) {
	PDF_TRY(p) { PDF_closepath_stroke(p); } PDF_CATCH(p) { }
}

void _PDF_concat(PDF *p, double a, double b, double c, double d, double e, double f) {
	PDF_TRY(p) { PDF_concat(p, a, b, c, d, e, f); } PDF_CATCH(p) { }
}

void _PDF_continue_text(PDF *p, const char *text) {
	PDF_TRY(p) { PDF_continue_text(p, text); } PDF_CATCH(p) { }
}

void _PDF_continue_text2(PDF *p, const char *text, int len) {
	PDF_TRY(p) { PDF_continue_text2(p, text, len); } PDF_CATCH(p) { }
}

int _PDF_create_3dview(PDF *p, const char *username, int len, const char *optlist) {
	PDF_TRY(p) { return PDF_create_3dview(p, username, len, optlist); } PDF_CATCH(p) { } return -1;
}

int _PDF_create_action(PDF *p, const char *type, const char *optlist) {
	PDF_TRY(p) { return PDF_create_action(p, type, optlist); } PDF_CATCH(p) { } return -1;
}

void _PDF_create_annotation(PDF *p, double llx, double lly, double urx, double ury, const char *type, const char *optlist) {
	PDF_TRY(p) { PDF_create_annotation(p, llx, lly, urx, ury, type, optlist); } PDF_CATCH(p) { }
}

int _PDF_create_bookmark(PDF *p, const char *text, int len, const char *optlist) {
	PDF_TRY(p) { return PDF_create_bookmark(p, text, len, optlist); } PDF_CATCH(p) { } return -1;
}

void _PDF_create_field(PDF *p, double llx, double lly, double urx, double ury, const char *name, int len, const char *type, const char *optlist) {
	PDF_TRY(p) { PDF_create_field(p, llx, lly, urx, ury, name, len, type, optlist); } PDF_CATCH(p) { }
}

void _PDF_create_fieldgroup(PDF *p, const char *name, int len, const char *optlist) {
	PDF_TRY(p) { PDF_create_fieldgroup(p, name, len, optlist); } PDF_CATCH(p) { }
}

int _PDF_create_gstate(PDF *p, const char *optlist) {
	PDF_TRY(p) { return PDF_create_gstate(p, optlist); } PDF_CATCH(p) { } return -1;
}

void _PDF_create_pvf(PDF *p, const char *filename, int len, const void *data, size_t size, const char *optlist) {
	PDF_TRY(p) { PDF_create_pvf(p, filename, len, data, size, optlist); } PDF_CATCH(p) { }
}

int _PDF_create_textflow(PDF *p, const char *text, int len, const char *optlist) {
	PDF_TRY(p) { return PDF_create_textflow(p, text, len, optlist); } PDF_CATCH(p) { } return -1;
}

void _PDF_curveto(PDF *p, double x_1, double y_1, double x_2, double y_2, double x_3, double y_3) {
	PDF_TRY(p) { PDF_curveto(p, x_1, y_1, x_2, y_2, x_3, y_3); } PDF_CATCH(p) { }
}

int _PDF_define_layer(PDF *p, const char *name, int len, const char *optlist) {
	PDF_TRY(p) { return PDF_define_layer(p, name, len, optlist); } PDF_CATCH(p) { } return -1;
}

void _PDF_delete(PDF *p) {
	PDF_delete(p);
}

void _PDF_delete_path(PDF *p, int path) {
	PDF_TRY(p) { PDF_delete_path(p, path); } PDF_CATCH(p) { }
}

int _PDF_delete_pvf(PDF *p, const char *filename, int len) {
	PDF_TRY(p) { return PDF_delete_pvf(p, filename, len); } PDF_CATCH(p) { } return -1;
}

void _PDF_delete_table(PDF *p, int table, const char *optlist) {
	PDF_TRY(p) { PDF_delete_table(p, table, optlist); } PDF_CATCH(p) { }
}

void _PDF_delete_textflow(PDF *p, int textflow) {
	PDF_TRY(p) { PDF_delete_textflow(p, textflow); } PDF_CATCH(p) { }
}

void _PDF_draw_path(PDF *p, int path, double x, double y, const char *optlist) {
	PDF_TRY(p) { PDF_draw_path(p, path, x, y, optlist); } PDF_CATCH(p) { }
}

void _PDF_ellipse(PDF *p, double x, double y, double rx, double ry) {
	PDF_TRY(p) { PDF_ellipse(p, x, y, rx, ry); } PDF_CATCH(p) { }
}

void _PDF_encoding_set_char(PDF *p, const char *encoding, int slot, const char *glyphname, int uv) {
	PDF_TRY(p) { PDF_encoding_set_char(p, encoding, slot, glyphname, uv); } PDF_CATCH(p) { }
}

void _PDF_end_document(PDF *p, const char *optlist) {
	PDF_TRY(p) { PDF_end_document(p, optlist); } PDF_CATCH(p) { }
}

void _PDF_end_font(PDF *p) {
	PDF_TRY(p) { PDF_end_font(p); } PDF_CATCH(p) { }
}

void _PDF_end_glyph(PDF *p) {
	PDF_TRY(p) { PDF_end_glyph(p); } PDF_CATCH(p) { }
}

void _PDF_end_item(PDF *p, int id) {
	PDF_TRY(p) { PDF_end_item(p, id); } PDF_CATCH(p) { }
}

void _PDF_end_layer(PDF *p) {
	PDF_TRY(p) { PDF_end_layer(p); } PDF_CATCH(p) { }
}

void _PDF_end_mc(PDF *p) {
	PDF_TRY(p) { PDF_end_mc(p); } PDF_CATCH(p) { }
}

void _PDF_end_page_ext(PDF *p, const char *optlist) {
	PDF_TRY(p) { PDF_end_page_ext(p, optlist); } PDF_CATCH(p) { }
}

void _PDF_end_pattern(PDF *p) {
	PDF_TRY(p) { PDF_end_pattern(p); } PDF_CATCH(p) { }
}

void _PDF_end_template_ext(PDF *p, double width, double height) {
	PDF_TRY(p) { PDF_end_template_ext(p, width, height); } PDF_CATCH(p) { }
}

void _PDF_endpath(PDF *p) {
	PDF_TRY(p) { PDF_endpath(p); } PDF_CATCH(p) { }
}

void _PDF_fill(PDF *p) {
	PDF_TRY(p) { PDF_fill(p); } PDF_CATCH(p) { }
}

int _PDF_fill_imageblock(PDF *p, int page, const char *blockname, int image, const char *optlist) {
	PDF_TRY(p) { return PDF_fill_imageblock(p, page, blockname, image, optlist); } PDF_CATCH(p) { } return -1;
}

int _PDF_fill_pdfblock(PDF *p, int page, const char *blockname, int contents, const char *optlist) {
	PDF_TRY(p) { return PDF_fill_pdfblock(p, page, blockname, contents, optlist); } PDF_CATCH(p) { } return -1;
}

void _PDF_fill_stroke(PDF *p) {
	PDF_TRY(p) { PDF_fill_stroke(p); } PDF_CATCH(p) { }
}

int _PDF_fill_textblock(PDF *p, int page, const char *blockname, const char *text, int len, const char *optlist) {
	PDF_TRY(p) { return PDF_fill_textblock(p, page, blockname, text, len, optlist); } PDF_CATCH(p) { } return -1;
}

void _PDF_fit_graphics(PDF *p, int graphics, double x, double y, const char *optlist) {
	PDF_TRY(p) { PDF_fit_graphics(p, graphics, x, y, optlist); } PDF_CATCH(p) { }
}

void _PDF_fit_image(PDF *p, int image, double x, double y, const char *optlist) {
	PDF_TRY(p) { PDF_fit_image(p, image, x, y, optlist); } PDF_CATCH(p) { }
}

void _PDF_fit_pdi_page(PDF *p, int page, double x, double y, const char *optlist) {
	PDF_TRY(p) { PDF_fit_pdi_page(p, page, x, y, optlist); } PDF_CATCH(p) { }
}

const char * _PDF_fit_table(PDF *p, int table, double llx, double lly, double urx, double ury, const char *optlist) {
	PDF_TRY(p) { return PDF_fit_table(p, table, llx, lly, urx, ury, optlist); } PDF_CATCH(p) { } return "";
}

const char * _PDF_fit_textflow(PDF *p, int textflow, double llx, double lly, double urx, double ury, const char *optlist) {
	PDF_TRY(p) { return PDF_fit_textflow(p, textflow, llx, lly, urx, ury, optlist); } PDF_CATCH(p) { } return "";
}

void _PDF_fit_textline(PDF *p, const char *text, int len, double x, double y, const char *optlist) {
	PDF_TRY(p) { PDF_fit_textline(p, text, len, x, y, optlist); } PDF_CATCH(p) { }
}

const char * _PDF_get_apiname(PDF *p) {
	PDF_TRY(p) { return PDF_get_apiname(p); } PDF_CATCH(p) { } return "";
}

const char * _PDF_get_buffer(PDF *p, long *size) {
	PDF_TRY(p) { return PDF_get_buffer(p, size); } PDF_CATCH(p) { } return "";
}

const char * _PDF_get_errmsg(PDF *p) {
	PDF_TRY(p) { return PDF_get_errmsg(p); } PDF_CATCH(p) { } return "";
}

int _PDF_get_errnum(PDF *p) {
	PDF_TRY(p) { return PDF_get_errnum(p); } PDF_CATCH(p) { } return 0;
}

const char * _PDF_get_parameter(PDF *p, const char *key, double modifier) {
	PDF_TRY(p) { return PDF_get_parameter(p, key, modifier); } PDF_CATCH(p) { } return "";
}

double _PDF_get_value(PDF *p, const char *key, double modifier) {
	PDF_TRY(p) { return PDF_get_value(p, key, modifier); } PDF_CATCH(p) { } return -1;
}

double _PDF_info_font(PDF *p, int font, const char *keyword, const char *optlist) {
	PDF_TRY(p) { return PDF_info_font(p, font, keyword, optlist); } PDF_CATCH(p) { } return -1;
}

double _PDF_info_graphics(PDF *p, int graphics, const char *keyword, const char *optlist) {
	PDF_TRY(p) { return PDF_info_graphics(p, graphics, keyword, optlist); } PDF_CATCH(p) { } return -1;
}

double _PDF_info_image(PDF *p, int image, const char *keyword, const char *optlist) {
	PDF_TRY(p) { return PDF_info_image(p, image, keyword, optlist); } PDF_CATCH(p) { } return -1;
}

double _PDF_info_matchbox(PDF *p, const char *boxname, int len, int num, const char *keyword) {
	PDF_TRY(p) { return PDF_info_matchbox(p, boxname, len, num, keyword); } PDF_CATCH(p) { } return -1;
}

double _PDF_info_path(PDF *p, int path, const char *keyword, const char *optlist) {
	PDF_TRY(p) { return PDF_info_path(p, path, keyword, optlist); } PDF_CATCH(p) { } return -1;
}

double _PDF_info_pdi_page(PDF *p, int page, const char *keyword, const char *optlist) {
	PDF_TRY(p) { return PDF_info_pdi_page(p, page, keyword, optlist); } PDF_CATCH(p) { } return -1;
}

double _PDF_info_table(PDF *p, int table, const char *keyword) {
	PDF_TRY(p) { return PDF_info_table(p, table, keyword); } PDF_CATCH(p) { } return -1;
}

double _PDF_info_textflow(PDF *p, int textflow, const char *keyword) {
	PDF_TRY(p) { return PDF_info_textflow(p, textflow, keyword); } PDF_CATCH(p) { } return -1;
}

double _PDF_info_textline(PDF *p, const char *text, int len, const char *keyword, const char *optlist) {
	PDF_TRY(p) { return PDF_info_textline(p, text, len, keyword, optlist); } PDF_CATCH(p) { } return -1;
}

void _PDF_initgraphics(PDF *p) {
	PDF_TRY(p) { PDF_initgraphics(p); } PDF_CATCH(p) { }
}

void _PDF_lineto(PDF *p, double x, double y) {
	PDF_TRY(p) { PDF_lineto(p, x, y); } PDF_CATCH(p) { }
}

int _PDF_load_3ddata(PDF *p, const char *filename, int len, const char *optlist) {
	PDF_TRY(p) { return PDF_load_3ddata(p, filename, len, optlist); } PDF_CATCH(p) { } return -1;
}

int _PDF_load_font(PDF *p, const char *fontname, int len, const char *encoding, const char *optlist) {
	PDF_TRY(p) { return PDF_load_font(p, fontname, len, encoding, optlist); } PDF_CATCH(p) { } return -1;
}

int _PDF_load_graphics(PDF *p, const char *graphicstype, const char *filename, int len, const char *optlist) {
	PDF_TRY(p) { return PDF_load_graphics(p, graphicstype, filename, len, optlist); } PDF_CATCH(p) { } return -1;
}

int _PDF_load_iccprofile(PDF *p, const char *profilename, int len, const char *optlist) {
	PDF_TRY(p) { return PDF_load_iccprofile(p, profilename, len, optlist); } PDF_CATCH(p) { } return -1;
}

int _PDF_load_image(PDF *p, const char *imagetype, const char *filename, int len, const char *optlist) {
	PDF_TRY(p) { return PDF_load_image(p, imagetype, filename, len, optlist); } PDF_CATCH(p) { } return -1;
}

int _PDF_makespotcolor(PDF *p, const char *spotname, int reserved) {
	PDF_TRY(p) { return PDF_makespotcolor(p, spotname, reserved); } PDF_CATCH(p) { } return -1;
}

void _PDF_mc_point(PDF *p, const char *tag, const char *optlist) {
	PDF_TRY(p) { PDF_mc_point(p, tag, optlist); } PDF_CATCH(p) { }
}

void _PDF_moveto(PDF *p, double x, double y) {
	PDF_TRY(p) { PDF_moveto(p, x, y); } PDF_CATCH(p) { }
}

int _PDF_open_pdi_document(PDF *p, const char *filename, int len, const char *optlist) {
	PDF_TRY(p) { return PDF_open_pdi_document(p, filename, len, optlist); } PDF_CATCH(p) { } return -1;
}

int _PDF_open_pdi_page(PDF *p, int doc, int pagenumber, const char *optlist) {
	PDF_TRY(p) { return PDF_open_pdi_page(p, doc, pagenumber, optlist); } PDF_CATCH(p) { } return -1;
}

double _PDF_pcos_get_number(PDF *p, int doc, const char *path) {
	PDF_TRY(p) { return PDF_pcos_get_number(p, doc, path); } PDF_CATCH(p) { } return -1;
}

const char * _PDF_pcos_get_string(PDF *p, int doc, const char *path) {
	PDF_TRY(p) { return PDF_pcos_get_string(p, doc, path); } PDF_CATCH(p) { } return "";
}

const unsigned char * _PDF_pcos_get_stream(PDF *p, int doc, int *length, const char *optlist, const char *path) {
	unsigned char *r; PDF_TRY(p) { return PDF_pcos_get_stream(p, doc, length, optlist, path); } PDF_CATCH(p) { } return r;
}

void _PDF_poca_delete(PDF *p, int container, const char *optlist) {
	PDF_TRY(p) { PDF_poca_delete(p, container, optlist); } PDF_CATCH(p) { }
}

void _PDF_poca_insert(PDF *p, int container, const char *optlist) {
	PDF_TRY(p) { PDF_poca_insert(p, container, optlist); } PDF_CATCH(p) { }
}

int _PDF_poca_new(PDF *p, const char *optlist) {
	PDF_TRY(p) { return PDF_poca_new(p, optlist); } PDF_CATCH(p) { } return -1;
}

void _PDF_poca_remove(PDF *p, int container, const char *optlist) {
	PDF_TRY(p) { PDF_poca_remove(p, container, optlist); } PDF_CATCH(p) { }
}

int _PDF_process_pdi(PDF *p, int doc, int page, const char *optlist) {
	PDF_TRY(p) { return PDF_process_pdi(p, doc, page, optlist); } PDF_CATCH(p) { } return -1;
}

void _PDF_rcurveto(PDF *p, double x_1, double y_1, double x_2, double y_2, double x_3, double y_3) {
	PDF_TRY(p) { PDF_rcurveto(p, x_1, y_1, x_2, y_2, x_3, y_3); } PDF_CATCH(p) { }
}

void _PDF_rect(PDF *p, double x, double y, double width, double height) {
	PDF_TRY(p) { PDF_rect(p, x, y, width, height); } PDF_CATCH(p) { }
}

void _PDF_restore(PDF *p) {
	PDF_TRY(p) { PDF_restore(p); } PDF_CATCH(p) { }
}

void _PDF_resume_page(PDF *p, const char *optlist) {
	PDF_TRY(p) { PDF_resume_page(p, optlist); } PDF_CATCH(p) { }
}

void _PDF_rotate(PDF *p, double phi) {
	PDF_TRY(p) { PDF_rotate(p, phi); } PDF_CATCH(p) { }
}

void _PDF_save(PDF *p) {
	PDF_TRY(p) { PDF_save(p); } PDF_CATCH(p) { }
}

void _PDF_scale(PDF *p, double sx, double sy) {
	PDF_TRY(p) { PDF_scale(p, sx, sy); } PDF_CATCH(p) { }
}

void _PDF_set_graphics_option(PDF *p, const char *optlist) {
	PDF_TRY(p) { PDF_set_graphics_option(p, optlist); } PDF_CATCH(p) { }
}

void _PDF_set_gstate(PDF *p, int gstate) {
	PDF_TRY(p) { PDF_set_gstate(p, gstate); } PDF_CATCH(p) { }
}

void _PDF_set_info(PDF *p, const char *key, const char *value) {
	PDF_TRY(p) { PDF_set_info(p, key, value); } PDF_CATCH(p) { }
}

void _PDF_set_info2(PDF *p, const char *key, const char *value, int len) {
	PDF_TRY(p) { PDF_set_info2(p, key, value, len); } PDF_CATCH(p) { }
}

void _PDF_set_layer_dependency(PDF *p, const char *type, const char *optlist) {
	PDF_TRY(p) { PDF_set_layer_dependency(p, type, optlist); } PDF_CATCH(p) { }
}

void _PDF_set_option(PDF *p, const char *optlist) {
	PDF_TRY(p) { PDF_set_option(p, optlist); } PDF_CATCH(p) { }
}

void _PDF_set_parameter(PDF *p, const char *key, const char *value) {
	PDF_TRY(p) { PDF_set_parameter(p, key, value); } PDF_CATCH(p) { }
}

void _PDF_set_text_pos(PDF *p, double x, double y) {
	PDF_TRY(p) { PDF_set_text_pos(p, x, y); } PDF_CATCH(p) { }
}

void _PDF_set_value(PDF *p, const char *key, double value) {
	PDF_TRY(p) { PDF_set_value(p, key, value); } PDF_CATCH(p) { }
}

void _PDF_setcolor(PDF *p, const char *fstype, const char *colorspace, double c1, double c2, double c3, double c4) {
	PDF_TRY(p) { PDF_setcolor(p, fstype, colorspace, c1, c2, c3, c4); } PDF_CATCH(p) { }
}

void _PDF_setdash(PDF *p, double b, double w) {
	PDF_TRY(p) { PDF_setdash(p, b, w); } PDF_CATCH(p) { }
}

void _PDF_setdashpattern(PDF *p, const char *optlist) {
	PDF_TRY(p) { PDF_setdashpattern(p, optlist); } PDF_CATCH(p) { }
}

void _PDF_setflat(PDF *p, double flatness) {
	PDF_TRY(p) { PDF_setflat(p, flatness); } PDF_CATCH(p) { }
}

void _PDF_setfont(PDF *p, int font, double fontsize) {
	PDF_TRY(p) { PDF_setfont(p, font, fontsize); } PDF_CATCH(p) { }
}

void _PDF_setlinecap(PDF *p, int linecap) {
	PDF_TRY(p) { PDF_setlinecap(p, linecap); } PDF_CATCH(p) { }
}

void _PDF_setlinejoin(PDF *p, int linejoin) {
	PDF_TRY(p) { PDF_setlinejoin(p, linejoin); } PDF_CATCH(p) { }
}

void _PDF_setlinewidth(PDF *p, double width) {
	PDF_TRY(p) { PDF_setlinewidth(p, width); } PDF_CATCH(p) { }
}

void _PDF_setmatrix(PDF *p, double a, double b, double c, double d, double e, double f) {
	PDF_TRY(p) { PDF_setmatrix(p, a, b, c, d, e, f); } PDF_CATCH(p) { }
}

void _PDF_setmiterlimit(PDF *p, double miter) {
	PDF_TRY(p) { PDF_setmiterlimit(p, miter); } PDF_CATCH(p) { }
}

int _PDF_shading(PDF *p, const char *shtype, double x_0, double y_0, double x_1, double y_1, double c_1, double c_2, double c_3, double c_4, const char *optlist) {
	PDF_TRY(p) { PDF_shading(p, shtype, x_0, y_0, x_1, y_1, c_1, c_2, c_3, c_4, optlist); } PDF_CATCH(p) { } return 0;
}

int _PDF_shading_pattern(PDF *p, int shading, const char *optlist) {
	PDF_TRY(p) { return PDF_shading_pattern(p, shading, optlist); } PDF_CATCH(p) { } return -1;
}

void _PDF_shfill(PDF *p, int shading) {
	PDF_TRY(p) { PDF_shfill(p, shading); } PDF_CATCH(p) { }
}

void _PDF_show(PDF *p, const char *text) {
	PDF_TRY(p) { PDF_show(p, text); } PDF_CATCH(p) { }
}

void _PDF_show2(PDF *p, const char *text, int len) {
	PDF_TRY(p) { PDF_show2(p, text, len); } PDF_CATCH(p) { }
}

void _PDF_show_xy(PDF *p, const char *text, double x, double y) {
	PDF_TRY(p) { PDF_show_xy(p, text, x, y); } PDF_CATCH(p) { }
}

void _PDF_show_xy2(PDF *p, const char *text, int len, double x, double y) {
	PDF_TRY(p) { PDF_show_xy2(p, text, len, x, y); } PDF_CATCH(p) { }
}

void _PDF_skew(PDF *p, double alpha, double beta) {
	PDF_TRY(p) { PDF_skew(p, alpha, beta); } PDF_CATCH(p) { }
}

double _PDF_stringwidth(PDF *p, const char *text, int font, double fontsize) {
	PDF_TRY(p) { return PDF_stringwidth(p, text, font, fontsize); } PDF_CATCH(p) { } return -1;
}

double _PDF_stringwidth2(PDF *p, const char *text, int len, int font, double fontsize) {
	PDF_TRY(p) { return PDF_stringwidth2(p, text, len, font, fontsize); } PDF_CATCH(p) { } return -1;
}

void _PDF_stroke(PDF *p) {
	PDF_TRY(p) { PDF_stroke(p); } PDF_CATCH(p) { }
}

void _PDF_suspend_page(PDF *p, const char *optlist) {
	PDF_TRY(p) { PDF_suspend_page(p, optlist); } PDF_CATCH(p) { }
}

void _PDF_translate(PDF *p, double tx, double ty) {
	PDF_TRY(p) { PDF_translate(p, tx, ty); } PDF_CATCH(p) { }
}

const char * _PDF_utf16_to_utf8(PDF *p, const char *utf16string, int len, int *size) {
	PDF_TRY(p) { return PDF_utf16_to_utf8(p, utf16string, len, size); } PDF_CATCH(p) { } return "";
}

const char * _PDF_utf8_to_utf16(PDF *p, const char *utf8string, const char *ordering, int *size) {
	PDF_TRY(p) { return PDF_utf8_to_utf16(p, utf8string, ordering, size); } PDF_CATCH(p) { } return "";
}

const char * _PDF_utf32_to_utf8(PDF *p, const char *utf32string, int len, int *size) {
	PDF_TRY(p) { return PDF_utf32_to_utf8(p, utf32string, len, size); } PDF_CATCH(p) { } return "";
}

const char * _PDF_utf8_to_utf32(PDF *p, const char *utf8string, const char *ordering, int *size) {
	PDF_TRY(p) { return PDF_utf8_to_utf32(p, utf8string, ordering, size); } PDF_CATCH(p) { } return "";
}

const char * _PDF_utf16_to_utf32(PDF *p, const char *utf16string, int len, const char *ordering, int *size) {
	PDF_TRY(p) { return PDF_utf16_to_utf32(p, utf16string, len, ordering, size); } PDF_CATCH(p) { } return "";
}

const char * _PDF_utf32_to_utf16(PDF *p, const char *utf32string, int len, const char *ordering, int *size) {
	PDF_TRY(p) { return PDF_utf32_to_utf16(p, utf32string, len, ordering, size); } PDF_CATCH(p) { } return "";
}
