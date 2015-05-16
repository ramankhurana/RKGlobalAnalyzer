classname=$1
now=`date`
author=`whoami`

cat > ${classname}.h <<EOF
// Original class : ${classname}.h
// Created By     : $author 
// Created On     : $now

#ifndef ${classname}_h_
#define ${classname}_h_

class ${classname} {
  ${classname}();
  ~${classname}();

  public:

  protected:

  private:

};
#endif

EOF