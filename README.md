<!DOCTYPE html><html><head><meta charset="utf-8"><style>/* Fonts */

/* Body */
html { font-size: 100%; overflow-y: scroll; -webkit-text-size-adjust: 100%; -ms-text-size-adjust: 100%; }

body{
  color:#4d4d4c;
  font-family:Georgia, Palatino, 'Palatino Linotype', Times, 'Times New Roman',
              "Hiragino Sans GB", "STXihei", "微软雅黑", serif;
  font-size:12px;
  line-height:1.5em;
  background:#fefefe;
  width: 45em;
  margin: 10px auto;
  padding: 30px;
  border: 1px solid #ddd;
  outline: 1300px solid #f8f8f8;
}

/* Links */
a{ color: #06d; text-decoration:none; }
a:hover{ color: #06e; text-decoration: underline; }
a:active{ color:#faa700; }
a:focus{ outline: thin dotted; }
a:hover, a:active{ outline: 0; }

::-moz-selection { background:rgba(255,255,0,0.3); color:#000 }
::selection { background:rgba(255,255,0,0.3); color:#000 }

a::-moz-selection { background:rgba(255,255,0,0.3); color:#0645ad }
a::selection { background:rgba(255,255,0,0.3); color:#0645ad }

/* Header Anchor Links*/
a.headeranchor-link {
  color:#111;
  border: 0;
  margin-left: -20px;
  padding-right: 6px;
  cursor: pointer;
  position: absolute;
  display: block;
  top: 0;
  left: 0;
  bottom: 0;
}

span.headeranchor {
  font: normal normal 16px octicons-anchor;
  line-height: 1;
  -moz-osx-font-smoothing: grayscale;
  -webkit-user-select: none;
  -moz-user-select: none;
  -ms-user-select: none;
  user-select: none;
}

a.headeranchor-link:hover { text-decoration: none;}
a.headeranchor-link:visited { color:#4d4d4c; }
a.headeranchor-link:active { color:#4d4d4c; }
a.headeranchor-link:hover span.headeranchor:before { content: '\f05c'; }
h1:hover a span.headeranchor:before { content: '\f05c'; }
h2:hover a span.headeranchor:before { content: '\f05c'; }
h3:hover a span.headeranchor:before { content: '\f05c'; }
h4:hover a span.headeranchor:before { content: '\f05c'; }
h5:hover a span.headeranchor:before { content: '\f05c'; }
h6:hover a span.headeranchor:before { content: '\f05c'; }

/* Paragraphs */
p { margin:1em 0; }

/* Images */
img {
  max-width:100%;
  border: 0;
  -ms-interpolation-mode: bicubic;
  vertical-align: middle;
}

/* Headers */
h1,h2,h3,h4,h5,h6 {
  font-weight:normal;
  color:#111;
  line-height: 1.7;
  position: relative;
}
h4,h5,h6{ font-weight: bold; }
h1 { font-size:2.5em; border-bottom: 1px solid #ddd;}
h2 { font-size:2em; border-bottom:1px solid #eee; padding-bottom: 5px; }
h3 { font-size:1.5em; }
h4 { font-size:1.2em; }
h5 { font-size:1em; }
h6 { font-size:0.9em; }

/* Block Quotes */
blockquote {
  color:#666666;
  margin:0;
  padding-left: 3em;
  border-left: 0.5em #EEE solid;
}
hr { display: block; height: 2px; border: 0; border-top: 1px solid #aaa;border-bottom: 1px solid #eee; margin: 1em 0; padding: 0; }

/* Raw Blocks */
span.backtick {
  border:1px solid #EAEAEA;
  border-radius:3px;
  background:#F8F8F8;
  padding:0 3px 0 3px;
}

pre, code, kbd, samp {
  color: #000;
  font-family: monospace;
  -webkit-border-radius: 3px;
  -moz-border-radius: 3px;
  border-radius: 3px;
  font-size: 0.88em;
  background-color: #F8F8F8;
  border: 1px solid #CCC;
}

pre {
  white-space: pre;
  white-space: pre-wrap;
  word-wrap: break-word;
  padding: 10px;
}

pre code { border: 0 }

code { padding: 0 3px 0 3px; }

/* Multimarkdown Critic Blocks */
span.critic_mark { background: #ff0; }
span.critic_delete { color: #c82829; text-decoration: line-through; }
span.critic_insert { color: #718c00 ; text-decoration: underline; }
span.critic_comment { color: #8e908c; font-style: italic; }

/* Inlines */
b, strong { font-weight: bold; }

ins { background: #ff9; color: #000; text-decoration: none; }

mark { background: #ff0; color: #000; font-style: italic; font-weight: bold; }

sub, sup { font-size: 75%; line-height: 0; position: relative; vertical-align: baseline; }
sup { top: -0.5em; }
sub { bottom: -0.25em; }

dfn { font-style: italic; }

/* Lists */
ul, ol { margin: 0.5em 0; padding: 0 0 0 2em; }
li p:last-child { margin:0 }
li.task-list-item { list-style-type: none; margin-left: -1.5em; }
li.task-list-item input { margin-right: .5em; }
li.task-list-item ul, li.task-list-item ol { margin-left: 1.5em; }
dd { margin: 0 0 0 2em; }

/* Tables */
table { border-collapse: collapse; border: 1px solid #ddd; }
table tr:nth-child(2n) { background-color: #f8f8f8; }
td, th { border: 1px solid #ddd; padding: 6px 13px; }

/* Codehilite Tables */
table.codehilitetable { border: 0; border-spacing: 0; width: 100%; }
td.linenos, td.code, table.codehilitetable td { border: 0; padding: 0; }
table.codehilitetable td:not(.linenos) div.linenodiv { padding: 0 !important; }
td.code { width: 100%; }
table.codehilitetable td.linenos div pre, td div.linenodiv pre {
  border: 0;
  border-top: 1px solid #CCC;
  border-left: 1px solid #CCC;
  border-right: 1px solid #CCC;
  border-bottom: 1px solid #CCC;
  -webkit-border-radius: 0;
  -moz-border-radius: 0;
  border-radius: 0;
  -webkit-border-top-left-radius: 3px;
  -webkit-border-bottom-left-radius: 3px;
  -moz-border-radius-topleft: 3px;
  -moz-border-radius-bottomleft: 3px;
  border-top-left-radius: 3px;
  border-bottom-left-radius: 3px;
}

table.codehilitetable td.code div pre {
  border: 0;
  border-top: 1px solid #CCC;
  border-right: 1px solid #CCC;
  border-bottom: 1px solid #CCC;
  -webkit-border-radius: 0;
  -moz-border-radius: 0;
  border-radius: 0;
  -webkit-border-top-right-radius: 3px;
  -webkit-border-bottom-right-radius: 3px;
  -moz-border-radius-topright: 3px;
  -moz-border-radius-bottomright: 3px;
  border-top-right-radius: 3px;
  border-bottom-right-radius: 3px;
}

/* Media */
@media only screen and (min-width: 480px) {
  body{ font-size:14px; }
}

@media only screen and (min-width: 768px) {
  body{ font-size:16px; }
}

@media print {
  * { background: transparent !important; color: black !important; filter:none !important; -ms-filter: none !important; }
  body{ font-size:12pt; max-width:100%; outline:none; border: 0;}
  a, a:visited { text-decoration: underline; }
  a.headeranchor-link { display: none; }
  hr { height: 1px; border:0; border-bottom:1px solid black; }
  a[href]:after { content: " (" attr(href) ")"; }
  abbr[title]:after { content: " (" attr(title) ")"; }
  .ir a:after, a[href^="javascript:"]:after, a[href^="#"]:after { content: ""; }
  pre, blockquote { border: 1px solid #999; padding-right: 1em; page-break-inside: avoid; }
  tr, img { page-break-inside: avoid; }
  img { max-width: 100% !important; }
  p, h2, h3 { orphans: 3; widows: 3; }
  h2, h3 { page-break-after: avoid; }
}
</style><title>README</title></head><body><p>2014Agenda project of SS.SYSU<br />
The socket version of Agenda Project.</p>
<p>==========<br />
<strong>Using boost::ptree lib to analyse JSON <br />
</strong>Using boost::asio lib to send and recive socket</p>
<p><strong>INSTRUCTION-ALL</strong><br />
1.To install boostlib ,just run:<br />
 $ sudo apt-get install libboost-all-dev //download boost lib</p>
<p>2.if your gcc version is lower than 4.7:<br />
    - change &ldquo;-std=c++11&rdquo; to &ldquo;-std=c++0x&rdquo;  in makefile(both in server/ and client)<br />
    - change &ldquo;std::array&rdquo; to &ldquo;boost::array&rdquo; in server/server.cpp and client/client.cpp (you can use ctrl+f to find) </p>
<p><strong>How to run Server</strong><br />
1. cd server<br />
2. make<br />
3. ./server<br />
4. press &ldquo;ctrl+C&rdquo; to stop server<br />
5. YOU CAN ONLY RUN ONE SERVER AT THE SAME TIME!</p>
<p><strong>How to run CLient</strong><br />
1. cd ../client<br />
2. make<br />
3. ./client/Agenda<br />
4. run ./server/server<br />
5. YOU CAN RUN AS MANY CLIENT AS YOU LIKE.<br />
6. follow the screen instructs to quit client</p>
<p><strong>TODO</strong><br />
1. use function pointer to replace if()else() in server.<br />
2. change json format to suit function pointer.<br />
==========</p>
<p>2014Agenda project of SS.SYSU</p></body></html>