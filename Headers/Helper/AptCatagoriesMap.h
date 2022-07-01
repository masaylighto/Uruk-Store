  #include<map>
  #include<string>  
//used to map Gui Catagories text to the actual catagories used by Apt
const std::map<std::string,std::string> _CatagoriesAliasMap=
{

{"All","*"},
{"Administration","admin"},
{"Mono/Cli","cli-mono"},
{"Communication","comm"},
{"Debug","debug"},
{"Development","devel"},
{"Documentation","doc"},
{"Fonts","font"},
{"Games","games"},
{"Graphics","graphics"},
{"Kernel","kernel"},
{"libraries","libs"},
{"Lisp","lisp"},
{"Mail","mail"},
{"Math","math"},
{"Meta Packages","metapackages"},
{"Miscellaneous","misc"},
{"Network","net"},
{"Ocaml","ocaml"},
{"Ruby","ruby"},
{"Python","python"},
{"Science","science"},
{"Sound","sound"},
{"Text","text"},
{"Utilities","utils"},
{"Web","web"},
{"Database","database"},
{"Editors","editors"},
{"Videos","video"},
{"Others","other"},
};