object present(string name, varargs mixed where...) {
   string what;
   int which;
   int i;
   object result;

   if(!where) where = ({ this_object() });

   for(i = 0; i < sizeof(where); i++) {
   
      if(where[i]<-"/std/container") {
         if (file_exists(name)) {
            result = where[i]->find_object_filename(name);
         } else if (file_exists(name + ".c")) {
            result = where[i]->find_object_filename(name + ".c");
         } 
         else if( sscanf(name, "%s %d", what, which) == 2 ) {
            result = where[i]->find_object_num(what, which);
            }
         else {
            result = where[i]->find_object_num(name, 1);
         }
      }
   if(result) return result;
   }
}
