#include <stdio.h>
#include "golang.c"
#include "pdflib.h"

void temp(PDF *p, const char *text, int len, double x, double y, const char *optlist);

void _PDF_activate_item(PDF *p, int id);

void _PDF_add_nameddest(PDF *p, const char *name, int len, const char *optlist);

int _PDF_add_path_point(PDF *p, int path, double x, double y, const char *type, const char *optlist);

int _PDF_add_portfolio_file(PDF *p, int folder, const char *filename, int len, const char *optlist);

int _PDF_add_portfolio_folder(PDF *p, int parent, const char *foldername, int len, const char *optlist);

int _PDF_add_table_cell(PDF *p, int table, int column, int row, const char *text, int len, const char *optlist);

int _PDF_add_textflow(PDF *p, int textflow, const char *text, int len, const char *optlist);

void _PDF_add_thumbnail(PDF *p, int image);

void _PDF_align(PDF *p, double dx, double dy);

void _PDF_arc(PDF *p, double x, double y, double r, double alpha, double beta);

void _PDF_arcn(PDF *p, double x, double y, double r, double alpha, double beta);

int _PDF_begin_document(PDF *p, const char *filename, int len, const char *optlist);

void _PDF_begin_font(PDF *p, const char *fontname, int len, double a, double b, double c, double d, double e, double f, const char *optlist);

void _PDF_begin_glyph(PDF *p, const char *glyphname, double wx, double llx, double lly, double urx, double ury);

int _PDF_begin_item(PDF *p, const char *tag, const char *optlist);

void _PDF_begin_layer(PDF *p, int layer);

void _PDF_begin_mc(PDF *p, const char *tag, const char *optlist);

void _PDF_begin_page_ext(PDF *p, double width, double height, const char *optlist);

int _PDF_begin_pattern(PDF *p, double width, double height, double xstep, double ystep, int painttype);

int _PDF_begin_template_ext(PDF *p, double width, double height, const char *optlist);

void _PDF_circle(PDF *p, double x, double y, double r);

void _PDF_circular_arc(PDF *p, double x_1, double y_1, double x_2, double y_2);

void _PDF_clip(PDF *p);

void _PDF_close_font(PDF *p, int font);

void _PDF_close_graphics(PDF *p, int graphics);

void _PDF_close_image(PDF *p, int image);

void _PDF_close_pdi_document(PDF *p, int doc);

void _PDF_close_pdi_page(PDF *p, int page);

void _PDF_closepath(PDF *p);

void _PDF_closepath_fill_stroke(PDF *p);

void _PDF_closepath_stroke(PDF *p);

void _PDF_concat(PDF *p, double a, double b, double c, double d, double e, double f);

void _PDF_continue_text(PDF *p, const char *text);

void _PDF_continue_text2(PDF *p, const char *text, int len);

int _PDF_create_3dview(PDF *p, const char *username, int len, const char *optlist);

int _PDF_create_action(PDF *p, const char *type, const char *optlist);

void _PDF_create_annotation(PDF *p, double llx, double lly, double urx, double ury, const char *type, const char *optlist);

int _PDF_create_bookmark(PDF *p, const char *text, int len, const char *optlist);

void _PDF_create_field(PDF *p, double llx, double lly, double urx, double ury, const char *name, int len, const char *type, const char *optlist);

void _PDF_create_fieldgroup(PDF *p, const char *name, int len, const char *optlist);

int _PDF_create_gstate(PDF *p, const char *optlist);

void _PDF_create_pvf(PDF *p, const char *filename, int len, const void *data, size_t size, const char *optlist);

int _PDF_create_textflow(PDF *p, const char *text, int len, const char *optlist);

void _PDF_curveto(PDF *p, double x_1, double y_1, double x_2, double y_2, double x_3, double y_3);

int _PDF_define_layer(PDF *p, const char *name, int len, const char *optlist);

void _PDF_delete(PDF *p);

void _PDF_delete_path(PDF *p, int path);

int _PDF_delete_pvf(PDF *p, const char *filename, int len);

void _PDF_delete_table(PDF *p, int table, const char *optlist);

void _PDF_delete_textflow(PDF *p, int textflow);

void _PDF_draw_path(PDF *p, int path, double x, double y, const char *optlist);

void _PDF_ellipse(PDF *p, double x, double y, double rx, double ry);

void _PDF_encoding_set_char(PDF *p, const char *encoding, int slot, const char *glyphname, int uv);

void _PDF_end_document(PDF *p, const char *optlist);

void _PDF_end_font(PDF *p);

void _PDF_end_glyph(PDF *p);

void _PDF_end_item(PDF *p, int id);

void _PDF_end_layer(PDF *p);

void _PDF_end_mc(PDF *p);

void _PDF_end_page_ext(PDF *p, const char *optlist);

void _PDF_end_pattern(PDF *p);

void _PDF_end_template_ext(PDF *p, double width, double height);

void _PDF_endpath(PDF *p);

void _PDF_fill(PDF *p);

int _PDF_fill_imageblock(PDF *p, int page, const char *blockname, int image, const char *optlist);

int _PDF_fill_pdfblock(PDF *p, int page, const char *blockname, int contents, const char *optlist);

void _PDF_fill_stroke(PDF *p);

int _PDF_fill_textblock(PDF *p, int page, const char *blockname, const char *text, int len, const char *optlist);

void _PDF_fit_graphics(PDF *p, int graphics, double x, double y, const char *optlist);

void _PDF_fit_image(PDF *p, int image, double x, double y, const char *optlist);

void _PDF_fit_pdi_page(PDF *p, int page, double x, double y, const char *optlist);

const char * _PDF_fit_table(PDF *p, int table, double llx, double lly, double urx, double ury, const char *optlist);

const char * _PDF_fit_textflow(PDF *p, int textflow, double llx, double lly, double urx, double ury, const char *optlist);

void _PDF_fit_textline(PDF *p, const char *text, int len, double x, double y, const char *optlist);

const char * _PDF_get_apiname(PDF *p);

const char * _PDF_get_buffer(PDF *p, long *size);

const char * _PDF_get_errmsg(PDF *p);

int _PDF_get_errnum(PDF *p);

const char * _PDF_get_parameter(PDF *p, const char *key, double modifier);

double _PDF_get_value(PDF *p, const char *key, double modifier);

double _PDF_info_font(PDF *p, int font, const char *keyword, const char *optlist);

double _PDF_info_graphics(PDF *p, int graphics, const char *keyword, const char *optlist);

double _PDF_info_image(PDF *p, int image, const char *keyword, const char *optlist);

double _PDF_info_matchbox(PDF *p, const char *boxname, int len, int num, const char *keyword);

double _PDF_info_path(PDF *p, int path, const char *keyword, const char *optlist);

double _PDF_info_pdi_page(PDF *p, int page, const char *keyword, const char *optlist);

double _PDF_info_table(PDF *p, int table, const char *keyword);

double _PDF_info_textflow(PDF *p, int textflow, const char *keyword);

double _PDF_info_textline(PDF *p, const char *text, int len, const char *keyword, const char *optlist);

void _PDF_initgraphics(PDF *p);

void _PDF_lineto(PDF *p, double x, double y);

int _PDF_load_3ddata(PDF *p, const char *filename, int len, const char *optlist);

int _PDF_load_font(PDF *p, const char *fontname, int len, const char *encoding, const char *optlist);

int _PDF_load_graphics(PDF *p, const char *graphicstype, const char *filename, int len, const char *optlist);

int _PDF_load_iccprofile(PDF *p, const char *profilename, int len, const char *optlist);

int _PDF_load_image(PDF *p, const char *imagetype, const char *filename, int len, const char *optlist);

int _PDF_makespotcolor(PDF *p, const char *spotname, int reserved);

void _PDF_mc_point(PDF *p, const char *tag, const char *optlist);

void _PDF_moveto(PDF *p, double x, double y);

int _PDF_open_pdi_document(PDF *p, const char *filename, int len, const char *optlist);

int _PDF_open_pdi_page(PDF *p, int doc, int pagenumber, const char *optlist);

double _PDF_pcos_get_number(PDF *p, int doc, const char *path);

const char * _PDF_pcos_get_string(PDF *p, int doc, const char *path);

const unsigned char * _PDF_pcos_get_stream(PDF *p, int doc, int *length, const char *optlist, const char *path);

void _PDF_poca_delete(PDF *p, int container, const char *optlist);

void _PDF_poca_insert(PDF *p, int container, const char *optlist);

int _PDF_poca_new(PDF *p, const char *optlist);

void _PDF_poca_remove(PDF *p, int container, const char *optlist);

int _PDF_process_pdi(PDF *p, int doc, int page, const char *optlist);

void _PDF_rect(PDF *p, double x, double y, double width, double height);

void _PDF_restore(PDF *p);

void _PDF_resume_page(PDF *p, const char *optlist);

void _PDF_rotate(PDF *p, double phi);

void _PDF_save(PDF *p);

void _PDF_scale(PDF *p, double sx, double sy);

void _PDF_set_graphics_option(PDF *p, const char *optlist);

void _PDF_set_gstate(PDF *p, int gstate);

void _PDF_set_info(PDF *p, const char *key, const char *value);

void _PDF_set_info2(PDF *p, const char *key, const char *value, int len);

void _PDF_set_layer_dependency(PDF *p, const char *type, const char *optlist);

void _PDF_set_option(PDF *p, const char *optlist);

void _PDF_set_parameter(PDF *p, const char *key, const char *value);

void _PDF_set_text_pos(PDF *p, double x, double y);

void _PDF_set_value(PDF *p, const char *key, double value);

void _PDF_setcolor(PDF *p, const char *fstype, const char *colorspace, double c1, double c2, double c3, double c4);

void _PDF_setdash(PDF *p, double b, double w);

void _PDF_setdashpattern(PDF *p, const char *optlist);

void _PDF_setflat(PDF *p, double flatness);

void _PDF_setfont(PDF *p, int font, double fontsize);

void _PDF_setlinecap(PDF *p, int linecap);

void _PDF_setlinejoin(PDF *p, int linejoin);

void _PDF_setlinewidth(PDF *p, double width);

void _PDF_setmatrix(PDF *p, double a, double b, double c, double d, double e, double f);

void _PDF_setmiterlimit(PDF *p, double miter);

int _PDF_shading(PDF *p, const char *shtype, double x_0, double y_0, double x_1, double y_1, double c_1, double c_2, double c_3, double c_4, const char *optlist);

int _PDF_shading_pattern(PDF *p, int shading, const char *optlist);

void _PDF_shfill(PDF *p, int shading);

void _PDF_show(PDF *p, const char *text);

void _PDF_show2(PDF *p, const char *text, int len);

void _PDF_show_xy(PDF *p, const char *text, double x, double y);

void _PDF_show_xy2(PDF *p, const char *text, int len, double x, double y);

void _PDF_skew(PDF *p, double alpha, double beta);

double _PDF_stringwidth(PDF *p, const char *text, int font, double fontsize);

double _PDF_stringwidth2(PDF *p, const char *text, int len, int font, double fontsize);

void _PDF_stroke(PDF *p);

void _PDF_suspend_page(PDF *p, const char *optlist);

void _PDF_translate(PDF *p, double tx, double ty);

const char * _PDF_utf16_to_utf8(PDF *p, const char *utf16string, int len, int *size);

const char * _PDF_utf8_to_utf16(PDF *p, const char *utf8string, const char *ordering, int *size);

const char * _PDF_utf32_to_utf8(PDF *p, const char *utf32string, int len, int *size);

const char * _PDF_utf8_to_utf32(PDF *p, const char *utf8string, const char *ordering, int *size);

const char * _PDF_utf16_to_utf32(PDF *p, const char *utf16string, int len, const char *ordering, int *size);

const char * _PDF_utf32_to_utf16(PDF *p, const char *utf32string, int len, const char *ordering, int *size);
