#include "html2c.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#define global_doc_html 0x0000
#define NULL ((void *)0)

char * global_doc_html;

//Initialize a new html document
document_html * init_html(){
    document_html * html = (document_html*) malloc(sizeof(document_html));
    if(html == NULL){
        return NULL;
    }
    //html->length = 0;
    //memcpy(html->html, (void *) {0}, sizeof(html->html));
    global_doc_html = (char *) malloc(sizeof(char)* 255);
   if(global_doc_html == NULL) {
    //    return NULL;
        exit(-1);
    }
    return html;
}

//Send to client the content HTML
void endhtml(document_html * doc_html){
    //send(doc_html->html, doc_html->length);
    printf("%s\n", global_doc_html);
    free(doc_html);
    free(global_doc_html);
}


const char * getEvent(event_type evt){
    switch (evt)
    {
    case ONAFTERPRINT:
        return "onafterprint";
    case    ONBEFOREPRINT:
        return "onbeforeprint";
    case     ONBEFOREUNLOAD:
        return "onbeforeunload";
    case    ONHASHCHANGE:
        return "onhashchange";
    case    ONLOAD:
        return "onload";
    case    ONMESSAGE:
        return "onmessage";
    case    ONOFFLINE:
        return "onoffline";
    case    ONONLINE:
        return "ononline";
    case    ONPAGEHIDE:
        return "onpagehide";
    case    ONPAGESHOW:
        return "onpageshow";
    case    ONPOPSTATE:
        return "onpopstate";
    case    ONRESIZE:
        return "onresize";
    case    ONSTORAGE:
        return "onstorage";
    case    ONUNLOAD:
        return "onunload";
    case    ONBLUR:
        return "onblur";
    case    ONCHANGE:
        return "onchange";
    case    ONFOCUS:
        return "onfocus";
    case    ONINPUT:
        return "oninput";
    case    ONINVALID:
        return "oninvalid";
    case    ONRESET:
        return "onreset";
    case    ONSELECT:
        return "onselect";
    case    ONSEARCH:
        return "onsearch";
    case    ONSUBMIT:
        return "onsubmit";
    case    ONCLICK:
        return "onclick";
    case    ONDBLCLICK:
        return "ondblclick";
    case    ONCONTEXTMENU:
        return "oncontextmenu";
    case    ONDRAG:
        return "ondrag";
    case    ONDRAGEND:
        return "ondragend";
    case    ONDRAGENTER:
        return "ondragenter";
    case    ONDRAGLEAVE:
        return "ondragleave";
    case    ONDRAGOVER:
        return "ondragover";
    case    ONDRAGSTART:
        return "ondragstart";
    case    ONDROP:
        return "ondrop";
    case    ONMOUSEDOWN:
        return "onmousedown";
    case    ONMOUSEMOVE:
        return "onmousemove";
    case    ONMOUSEOUT:
        return "onmouseout";
    case    ONMOUSEOVER:
        return "onmouseover";
    case    ONMOUSEUP:
        return "onmouseup";
    case    ONMOUSEWHEEL:
        return "onmousewheel";
    case    ONSCROLL:
        return "onscroll";
    case    ONSHOW:
        return "onshow";
    case    ONTOGGLE:
        return "ontoggle";
    case    ONWHEEL:
        return "onwheel";
    case    ONKEYDOWN:
        return "onkeydown";
    case    ONKEYPRESS:
        return "onkeypress";
    case    ONKEYUP:
        return "onkeyup";
    case    ONCOPY:
        return "oncopy";
    case    ONCUT:
        return "oncut";
    case    ONPASTE:
        return "onpaste";
    case    ONABORT:
        return "onabort";
    case    ONCANPLAY:
        return "oncanplay";
    case    ONCANPLAYTHROUGH:
        return "oncanplaythrough";
    case    ONCUECHANGE:
        return "oncuechange";
    case    ONDURATIONCHANGE:
        return "ondurationchange";
    case    ONEMPTIED:
        return "onemptied";
    case    ONENDED:
        return "onended";
    case    ONERROR:
        return "onerror";
    case    ONLOADEDDATA:
        return "onloadeddata";
    case    ONLOADEDMETADATA:
        return "onloadedmetadata";
    case    ONLOADSTART:
        return "onloadstart";
    case    ONPAUSE:
        return "onpause";
    case    ONPLAY:
        return "onplay";
    case    ONPLAYING:
        return "onplaying";
    case    ONPROGRESS:
        return "onprogress";
    case    ONRATECHANGE:
        return "onratechange";
    case    ONSEEKED:
        return "onseeked";
    case    ONSEEKING:
        return "onseeking";
    case    ONSTALLED:
        return "onstalled";
    case    ONSUSPEND:
        return "onsuspend";
    case    ONTIMEUPDATE:
        return "ontimeupdate";
    case    ONVOLUMECHANGE:
        return "onvolumechange";
    case ONWAITING:
        return "onwaiting";
    }
}

void DOCTYPE_HTML(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
         return ;
    }
    printf("okok!!!!\n");
    sprintf(global_doc_html, "%s\n<!DOCTYPE html>\n", global_doc_html);
    
    //return;
}
void ABBR(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</abbr>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<abbr %s style=\"%s\" %s data-lib=\"libv1\">%s</abbr>\n\r", global_doc_html, attributs , elems->innerHTML); 
   
}
void ACRONYM(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</acronym>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<acronym %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void ADDRESS(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</address>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<address %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void A(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</a>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<a %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void APPLET(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</applet>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<applet %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void AREA(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</area>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<area %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void ASIDE(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</aside>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<aside %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void AUDIO(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</audio>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<audio %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void BASE(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</base>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<base %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void BASEFONT(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</basefont>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<basefont %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void BDI(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</bdi>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<bdi %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void BDO(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</bdo>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<bdo %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void BGSOUND(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</bgsound>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<bgsound %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void BIG(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</big>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<big %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void BLOCKQUOTE(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</blockquote>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<blockquote %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void BODY(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</body>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<body %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void B(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</b>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<b %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void BR(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</br>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<br %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void BUTTON(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</button>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<button %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void CAPTION(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</caption>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<caption %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void CANVAS(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</canvas>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<canvas %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void CENTER(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</center>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<center %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void CITE(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</cite>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<cite %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void CODE(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</code>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<code %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void COLGROUP(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</colgroup>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<colgroup %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void COL(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</col>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<col %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void COMMENTS_HTML(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s -->\n\r", global_doc_html); 
        }
        return;
    }
    sprintf(global_doc_html, "%s\n<!-- %s\n\r", global_doc_html,  elems->innerHTML); 
   
}
void DATA(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</data>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<data %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void DATALIST(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</datalist>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<datalist %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void DD(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</dd>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<dd %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void DFN(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</dfn>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<dfn %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void DEL(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</del>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<del %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void DETAILS(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</details>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<details %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void DIALOG(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</dialog>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<dialog %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void DIR(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</dir>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<dir %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void DIV(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</div>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<div %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void DL(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</dl>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<dl %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void DT(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</dt>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<dt %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void EMBED(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</embed>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<embed %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void FIELDSET(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</fieldset>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<fieldset %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void FIGCAPTION(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</figcaption>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<figcaption %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void FIGURE(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</figure>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<figure %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void FONT(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</font>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<font %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void FOOTER(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</footer>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<footer %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void FORM(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</form>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<form %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void FRAME(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</frame>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<frame %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void FRAMESET(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</frameset>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<frameset %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void HEAD(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</head>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<head %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML);
    
}
void H1(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</h1>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<h1 %s style=\"%s\" %s data-lib=\"libv1\">%s</h1>\n\r", global_doc_html, attributs,  elems->innerHTML); 
   
}
void H2(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</h2>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<h2 %s style=\"%s\" %s data-lib=\"libv1\">%s</h2>\n\r", global_doc_html, attributs,  elems->innerHTML); 
   
}
void H3(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</h3>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<h3 %s style=\"%s\" %s data-lib=\"libv1\">%s</h3>\n\r", global_doc_html, attributs,  elems->innerHTML); 
   
}
void H4(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</h4>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<h4 %s style=\"%s\" %s data-lib=\"libv1\">%s</h4>\n\r", global_doc_html, attributs,  elems->innerHTML); 
   
}
void H5(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</h5>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<h5 %s style=\"%s\" %s data-lib=\"libv1\">%s</h5>\n\r", global_doc_html, attributs,  elems->innerHTML); 
   
}
void H6(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</h6>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<h6 %s style=\"%s\" %s data-lib=\"libv1\">%s</h6>\n\r", global_doc_html, attributs,  elems->innerHTML); 
   
}
void HGROUP(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</hgroup>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<hgroup %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void HTML(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</html>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<html %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML);
    
}
void IFRAME(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</iframe>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<iframe %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void IMG(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</img>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<img %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void INPUT(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</input>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<input %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void INS(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</ins>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<ins %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void ISINDEX(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</isindex>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<isindex %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void I(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</i>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<i %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void KDB(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</kdb>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<kdb %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void KEYGEN(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</keygen>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<keygen %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void LABEL(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</label>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<label %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void LEGEND(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</legend>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<legend %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void LI(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</li>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<li %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void MAIN(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</main>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<main %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void MARK(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</mark>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<mark %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void MARQUEE(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</marquee>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<marquee %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void MENUITEM(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</menuitem>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<menuitem %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void META(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</meta>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<meta %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void METER(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</meter>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<meter %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void NAV(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</nav>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<nav %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void NOBR(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</nobr>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<nobr %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void NOEMBED(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</noembed>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<noembed %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void NOSCRIPT(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</noscript>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<noscript %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void OBJECT(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</object>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<object %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void OPTGROUP(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</optgroup>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<optgroup %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void OPTION(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</option>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<option %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void OUTPUT(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</output>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<output %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void P(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</p>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    
    
    sprintf(global_doc_html, "%s\n<p %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
    //free(attributs);
}
void PARAM(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</param>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<param %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void EM(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</em>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<em %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void PRE(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</pre>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<pre %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void PROGRESS(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</progress>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<progress %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void Q(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</q>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<q %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void RP(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</rp>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<rp %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void RT(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</rt>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<rt %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void RUBY(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</ruby>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<ruby %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void S(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</s>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<s %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void SAMP(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</samp>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<samp %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void SCRIPT(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</script>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<script %s style=\"%s\" %s data-lib=\"libv1\">\n\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void SECTION(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</section>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<section %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void SMALL(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</small>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<small %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void SOURCE(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</source>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<source %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void SPACER(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</spacer>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<spacer %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void SPAN(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</span>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<span %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void STRIKE(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</strike>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<strike %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void STRONG(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</strong>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<strong %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void TAGNAME(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</tagname>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<tagname %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void SUB(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</sub>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<sub %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void SUP(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</sup>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<sup %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void SUMMARY(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</summary>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<summary %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void SVG(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</svg>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<svg %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void TABLE(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</table>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<table %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void TBODY(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</tbody>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<tbody %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void TD(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</td>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<td %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void TEMPLATE(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</template>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<template %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void TFOOT(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</tfoot>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<tfoot %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void TH(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</th>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<th %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void THEAD(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</thead>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<thead %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void TIME(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</time>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<time %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void TITLE(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</title>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<title %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void TR(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</tr>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<tr %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void TRACK(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</track>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<track %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void TT(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</tt>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<tt %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void U(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</u>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<u %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void VAR(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</var>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<var %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void VIDEO(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</video>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<video %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void WBR(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</wbr>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<wbr %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void XMP(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</xmp>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<xmp %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void LINK(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</link>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<link %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void NEXTID(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</nextid>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<nextid %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void NOFRAMES(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</noframes>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<noframes %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void OL(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</ol>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<ol %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void SELECT(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</select>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<select %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void TEXTAREA(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</textarea>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<textarea %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void HR(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</hr>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<hr %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void MAP(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</map>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<map %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void MENU(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</menu>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<menu %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void ARTICLE(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</article>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<article %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void HEADER(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</header>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<header %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void COMMAND(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</command>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<command %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void FENCEDFRAME(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</fencedframe>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<fenceframe %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void MATH(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</math>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<math %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void PLAINTEXT(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</plaintext>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<plaintext %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void PORTAL(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</portal>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<portal %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void RB(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</rb>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<rb %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void RTC(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</rtc>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<rtc %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void RTE(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</rte>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<rte %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void SEARCH(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</search>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<search %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void SLOT(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</clot>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<slot %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void STYLE(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</style>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<style %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}
void FREE(const html_elems* elems, EndTag end){
    if(end.typetag == END || elems == NULL){
        if(end.typetag == END){
            sprintf(global_doc_html, "%s</free>\n\r", global_doc_html); 
        }
        return;
    }
    int nbattributElem = 0;
    char attributs[24024];
    char attributs_style[15024];
    char attributs_event[15024];
    
    for(int i = 0; i < nbattributElem; i++){
        char temp[255] = {0};
        sprintf(temp, "accesskey=\"%d\" ", elems->attributs[i].accesskey);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " class=\"%s\" ", elems->attributs[i].class);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contentEditable=\"%d\" ", elems->attributs[i].contenteditable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " contextMenu=\"%s\" ", elems->attributs[i].contextmenu);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " data=\"%s\" ", elems->attributs[i].data_ptr);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dir=\"%s\" ", elems->attributs[i].dir);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " draggable=\"%d\" ", elems->attributs[i].draggable);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " dropZone=\"%d\" ", elems->attributs[i].dropzone);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " hidden=\"%d\" ", elems->attributs[i].hidden);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " id=\"%s\" ", elems->attributs[i].id);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " lang=\"%s\" ", elems->attributs[i].lang);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " spellCheck=\"%d\" ", elems->attributs[i].spellcheck);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " tabIndex=\"%d\" ", elems->attributs[i].tabindex);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " title=\"%s\" ", elems->attributs[i].title);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " translate=\"%d\" ", elems->attributs[i].translate);
        strcat(attributs, temp);
        //-----------------------------------
        sprintf(temp, " xml_lang=\"%s\" ", elems->attributs[i].xml_lang);
        strcat(attributs, temp);
        //-----------------------------------
        for(int s = 0; s < 0; s++){
            sprintf(attributs_style, "%s %s:%s; ", attributs_style, elems->attributs[i].style.styles[s].key, elems->attributs[i].style.styles[s].value);
        }
        for(int e = 0; e < 0; e++){
            sprintf(attributs_event, "%s %s=\"%s\" ", attributs_event, getEvent(elems->attributs[i].events[e].event), elems->attributs[i].events[e].script);
        }
    }
    sprintf(global_doc_html, "%s\n<free %s style=\"%s\" %s data-lib=\"libv1\">\n\t%s\n\r", global_doc_html, attributs, attributs_style, attributs_event,  elems->innerHTML); 
   
}