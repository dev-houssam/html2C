#ifndef _HTML_
#define _HTML_

#define BEGIN_DOCUMENT int main(int argc, const char * argv[]){printf("Hello::\n");document_html * root = init_html();/*html_elems list[64];*/
#define END_DOCUMENT return EXIT_SUCCESS;}



typedef enum Tag_Type{
    METADATA_TYPE=0,
    INLINE,
    BLOCK
} Tag_Type;

typedef enum Tag_Category{
    METADATA_CATEGORY=0,
    SCRIPTING,
    DOCUMENT_STRUCTURE,
    CONTENT,
    LINKING_CATEGORY,
    TEXT_FORMATTING,
    FORMS,
    LISTS,
    INTERACTIVE,
    MEDIA,
    TABLES
} Tag_Category;

typedef int bool;

#define TRUE  1
#define FALSE 0

typedef enum EndTag_type{
    BEG=0,
    END
}EndTag_type;

typedef struct EndTag{
   EndTag_type typetag;
}EndTag;

typedef enum dropzone_type
{
    COPY=0,
    MOVE,
    LINKING
} dropzone_type;

typedef struct KeyValue_type
{
    char key[255];
    char value[255];
} KeyValue_type;


typedef struct Style_type
{
    KeyValue_type styles[30];
} Style_type;

typedef enum event_type{
    ONAFTERPRINT=0,
    ONBEFOREPRINT,
    ONBEFOREUNLOAD,
    ONHASHCHANGE,
    ONLOAD,
    ONMESSAGE,
    ONOFFLINE,
    ONONLINE,
    ONPAGEHIDE,
    ONPAGESHOW,
    ONPOPSTATE,
    ONRESIZE,
    ONSTORAGE,
    ONUNLOAD,
    ONBLUR,
    ONCHANGE,
    ONFOCUS,
    ONINPUT,
    ONINVALID,
    ONRESET,
    ONSELECT,
    ONSEARCH,
    ONSUBMIT,
    ONCLICK,
    ONDBLCLICK,
    ONCONTEXTMENU,
    ONDRAG,
    ONDRAGEND,
    ONDRAGENTER,
    ONDRAGLEAVE,
    ONDRAGOVER,
    ONDRAGSTART,
    ONDROP,
    ONMOUSEDOWN,
    ONMOUSEMOVE,
    ONMOUSEOUT,
    ONMOUSEOVER,
    ONMOUSEUP,
    ONMOUSEWHEEL,
    ONSCROLL,
    ONSHOW,
    ONTOGGLE,
    ONWHEEL,
    ONKEYDOWN,
    ONKEYPRESS,
    ONKEYUP,
    ONCOPY,
    ONCUT,
    ONPASTE,
    ONABORT,
    ONCANPLAY,
    ONCANPLAYTHROUGH,
    ONCUECHANGE,
    ONDURATIONCHANGE,
    ONEMPTIED,
    ONENDED,
    ONERROR,
    ONLOADEDDATA,
    ONLOADEDMETADATA,
    ONLOADSTART,
    ONPAUSE,
    ONPLAY,
    ONPLAYING,
    ONPROGRESS,
    ONRATECHANGE,
    ONSEEKED,
    ONSEEKING,
    ONSTALLED,
    ONSUSPEND,
    ONTIMEUPDATE,
    ONVOLUMECHANGE,
    ONWAITING
}event_type;

typedef struct event_script
{
    event_type event;
    char script[255];
} event_script;


typedef struct html_attrs{
    int  accesskey;
    char class[255];
    bool contenteditable;
    char contextmenu[255];
    char data_ptr[255];
    char dir[255];
    bool draggable;
    dropzone_type dropzone;
    bool hidden;
    char id[255];
    char lang[255];
    bool spellcheck;
    Style_type style;
    int tabindex;
    char title[255];
    bool translate;
    char xml_lang[255];
    event_script events[64];
}html_attrs;



typedef struct html_elems{
    Tag_Type tag_type;
    Tag_Category tag_category;
    html_attrs attributs[20];
    char innerHTML[255];
    EndTag type;
} html_elems;

typedef struct document_html{

    long length;
    char html[1024];

} document_html;

//Initialize a new html document
document_html * init_html();

//Send to client the content HTML
void endhtml(document_html * doc_html);

const char * getEvent(event_type);

void DOCTYPE_HTML(const html_elems* elems, EndTag end);
void ABBR(const html_elems* elems, EndTag end);
void ACRONYM(const html_elems* elems, EndTag end);
void ADDRESS(const html_elems* elems, EndTag end);
void A(const html_elems* elems, EndTag end);
void APPLET(const html_elems* elems, EndTag end);
void AREA(const html_elems* elems, EndTag end);
void ASIDE(const html_elems* elems, EndTag end);
void AUDIO(const html_elems* elems, EndTag end);
void BASE(const html_elems* elems, EndTag end);
void BASEFONT(const html_elems* elems, EndTag end);
void BDI(const html_elems* elems, EndTag end);
void BDO(const html_elems* elems, EndTag end);
void BGSOUND(const html_elems* elems, EndTag end);
void BIG(const html_elems* elems, EndTag end);
void BLOCKQUOTE(const html_elems* elems, EndTag end);
void BODY(const html_elems* elems, EndTag end);
void B(const html_elems* elems, EndTag end);
void BR(const html_elems* elems, EndTag end);
void BUTTON(const html_elems* elems, EndTag end);
void CAPTION(const html_elems* elems, EndTag end);
void CANVAS(const html_elems* elems, EndTag end);
void CENTER(const html_elems* elems, EndTag end);
void CITE(const html_elems* elems, EndTag end);
void CODE(const html_elems* elems, EndTag end);
void COLGROUP(const html_elems* elems, EndTag end);
void COL(const html_elems* elems, EndTag end);
void COMMENTS_HTML(const html_elems* elems, EndTag end);
void DATA(const html_elems* elems, EndTag end);
void DATALIST(const html_elems* elems, EndTag end);
void DD(const html_elems* elems, EndTag end);
void DFN(const html_elems* elems, EndTag end);
void DEL(const html_elems* elems, EndTag end);
void DETAILS(const html_elems* elems, EndTag end);
void DIALOG(const html_elems* elems, EndTag end);
void DIR(const html_elems* elems, EndTag end);
void DIV(const html_elems* elems, EndTag end);
void DL(const html_elems* elems, EndTag end);
void DT(const html_elems* elems, EndTag end);
void EMBED(const html_elems* elems, EndTag end);
void FIELDSET(const html_elems* elems, EndTag end);
void FIGCAPTION(const html_elems* elems, EndTag end);
void FIGURE(const html_elems* elems, EndTag end);
void FONT(const html_elems* elems, EndTag end);
void FOOTER(const html_elems* elems, EndTag end);
void FORM(const html_elems* elems, EndTag end);
void FRAME(const html_elems* elems, EndTag end);
void FRAMESET(const html_elems* elems, EndTag end);
void HEAD(const html_elems* elems, EndTag end);
void H1(const html_elems* elems, EndTag end);
void H2(const html_elems* elems, EndTag end);
void H3(const html_elems* elems, EndTag end);
void H4(const html_elems* elems, EndTag end);
void H5(const html_elems* elems, EndTag end);
void H6(const html_elems* elems, EndTag end);
void HGROUP(const html_elems* elems, EndTag end);
void HTML(const html_elems* elems, EndTag end);
void IFRAME(const html_elems* elems, EndTag end);
void IMG(const html_elems* elems, EndTag end);
void INPUT(const html_elems* elems, EndTag end);
void INS(const html_elems* elems, EndTag end);
void ISINDEX(const html_elems* elems, EndTag end);
void I(const html_elems* elems, EndTag end);
void KDB(const html_elems* elems, EndTag end);
void KEYGEN(const html_elems* elems, EndTag end);
void LABEL(const html_elems* elems, EndTag end);
void LEGEND(const html_elems* elems, EndTag end);
void LI(const html_elems* elems, EndTag end);
void MAIN(const html_elems* elems, EndTag end);
void MARK(const html_elems* elems, EndTag end);
void MARQUEE(const html_elems* elems, EndTag end);
void MENUITEM(const html_elems* elems, EndTag end);
void META(const html_elems* elems, EndTag end);
void METER(const html_elems* elems, EndTag end);
void NAV(const html_elems* elems, EndTag end);
void NOBR(const html_elems* elems, EndTag end);
void NOEMBED(const html_elems* elems, EndTag end);
void NOSCRIPT(const html_elems* elems, EndTag end);
void OBJECT(const html_elems* elems, EndTag end);
void OPTGROUP(const html_elems* elems, EndTag end);
void OPTION(const html_elems* elems, EndTag end);
void OUTPUT(const html_elems* elems, EndTag end);
void P(const html_elems* elems, EndTag end);
void PARAM(const html_elems* elems, EndTag end);
void EM(const html_elems* elems, EndTag end);
void PRE(const html_elems* elems, EndTag end);
void PROGRESS(const html_elems* elems, EndTag end);
void Q(const html_elems* elems, EndTag end);
void RP(const html_elems* elems, EndTag end);
void RT(const html_elems* elems, EndTag end);
void RUBY(const html_elems* elems, EndTag end);
void S(const html_elems* elems, EndTag end);
void SAMP(const html_elems* elems, EndTag end);
void SCRIPT(const html_elems* elems, EndTag end);
void SECTION(const html_elems* elems, EndTag end);
void SMALL(const html_elems* elems, EndTag end);
void SOURCE(const html_elems* elems, EndTag end);
void SPACER(const html_elems* elems, EndTag end);
void SPAN(const html_elems* elems, EndTag end);
void STRIKE(const html_elems* elems, EndTag end);
void STRONG(const html_elems* elems, EndTag end);
void TAGNAME(const html_elems* elems, EndTag end);
void SUB(const html_elems* elems, EndTag end);
void SUP(const html_elems* elems, EndTag end);
void SUMMARY(const html_elems* elems, EndTag end);
void SVG(const html_elems* elems, EndTag end);
void TABLE(const html_elems* elems, EndTag end);
void TBODY(const html_elems* elems, EndTag end);
void TD(const html_elems* elems, EndTag end);
void TEMPLATE(const html_elems* elems, EndTag end);
void TFOOT(const html_elems* elems, EndTag end);
void TH(const html_elems* elems, EndTag end);
void THEAD(const html_elems* elems, EndTag end);
void TIME(const html_elems* elems, EndTag end);
void TITLE(const html_elems* elems, EndTag end);
void TR(const html_elems* elems, EndTag end);
void TRACK(const html_elems* elems, EndTag end);
void TT(const html_elems* elems, EndTag end);
void U(const html_elems* elems, EndTag end);
void VAR(const html_elems* elems, EndTag end);
void VIDEO(const html_elems* elems, EndTag end);
void WBR(const html_elems* elems, EndTag end);
void XMP(const html_elems* elems, EndTag end);
void LINK(const html_elems* elems, EndTag end);
void NEXTID(const html_elems* elems, EndTag end);
void NOFRAMES(const html_elems* elems, EndTag end);
void OL(const html_elems* elems, EndTag end);
void SELECT(const html_elems* elems, EndTag end);
void TEXTAREA(const html_elems* elems, EndTag end);
void HR(const html_elems* elems, EndTag end);
void MAP(const html_elems* elems, EndTag end);
void MENU(const html_elems* elems, EndTag end);
void ARTICLE(const html_elems* elems, EndTag end);
void HEADER(const html_elems* elems, EndTag end);
void COMMAND(const html_elems* elems, EndTag end);
void FENCEDFRAME(const html_elems* elems, EndTag end);
void MATH(const html_elems* elems, EndTag end);
void PLAINTEXT(const html_elems* elems, EndTag end);
void PORTAL(const html_elems* elems, EndTag end);
void RB(const html_elems* elems, EndTag end);
void RTC(const html_elems* elems, EndTag end);
void RTE(const html_elems* elems, EndTag end);
void SEARCH(const html_elems* elems, EndTag end);
void SLOT(const html_elems* elems, EndTag end);
void STYLE(const html_elems* elems, EndTag end);
void FREE(const html_elems* elems, EndTag end);
#endif