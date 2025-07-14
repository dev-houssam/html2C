# html2C
In this project, the HTML driven by C language. That allows to send directly to web client some HTML contents.

```c


BEGIN_DOCUMENT
    DOCTYPE_HTML(&(html_elems) {0}, (EndTag) {.typetag=BEG});
    /*HTML(&(html_elems) {
        /*.tag_type=INLINE,
        .tag_category=MEDIA,
        .innerHTML=" "
    }, (EndTag) {.typetag=BEG});
    HEAD(&(html_elems) {
        .innerHTML=" "
    }, (EndTag) {.typetag=BEG});

    META(&(html_elems){.innerHTML="ok"}, (EndTag) {.typetag=BEG});
    META(&(html_elems){}, (EndTag) {.typetag=END});

    STYLE(&(html_elems){
        .innerHTML="d \n"
        "ok"
    }, (EndTag) {.typetag=BEG});
    STYLE(&(html_elems){}, (EndTag) {.typetag=END});


    HEAD(NULL, (EndTag) {.typetag=END});
    
    /*------- BODY -------
    BODY(&(html_elems) {
        .innerHTML=" ppp"
    }, (EndTag) {.typetag=BEG});

    H1(&(html_elems) {
        .innerHTML="iii "
    }, (EndTag) {.typetag=BEG});

    H1(NULL,   (EndTag) {.typetag=END});*/

    Style_type styles; 
   int nbStyles = 30;
    for(int s = 0; s < nbStyles; s++){
        memcpy(styles.styles[s].key, (const char *)"0", 255);
        memcpy(styles.styles[s].value, (const char *)"0", 255);
        sprintf(styles.styles[s].key, "border");
        sprintf(styles.styles[s].value, "solid %dpx black", s*3+2);
    }

    html_attrs attributs_ = {
        .accesskey=88,
        .class="maclasse",
        .contenteditable=FALSE,
        .contextmenu="contexte",
        .data_ptr="madonnees",
        .dir="hello",
        .draggable=FALSE,
        .dropzone=COPY,
        .hidden=TRUE,
        .id="monId",
        .lang="fr",
        .spellcheck=TRUE,
        .style=styles,
        .tabindex=6,
        .title="Montitlee",
        .translate=TRUE,
        .xml_lang="XML_lANG",
        .events={{.event=ONCHANGE, .script="alert(99);"},
                {.event=ONCLICK, .script="alert('my click yeah!!!!!');"}
                },
    };
    
    
    P(&(html_elems) {
        .attributs={attributs_},
        .innerHTML="Here is text found in HTML Paragraph tag"
    }, (EndTag) {.typetag=BEG});


    P(NULL, (EndTag) {.typetag=END});

    SCRIPT(&(html_elems) {
        .innerHTML="let x = 8; alert(111);"
    }, (EndTag) {.typetag=BEG});
    SCRIPT(NULL, (EndTag) {.typetag=END});

   /* BODY(NULL, (EndTag) {.typetag=END});
    /*-------- FIN DU BODY ---------
    HTML(NULL, (EndTag) {.typetag=END});*/
    endhtml(root);
END_DOCUMENT

```


---

