SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

#echo File name: 
#read filename

#echo Output file name:
#read outputname

#gfortran -fdefault-real-8 -fdefault-double-8 $filename -o $SCRIPT_DIR/output/$outputname

gfortran -fdefault-real-8 -fdefault-double-8 P3estrelas_ultrarel2.f90 -o $SCRIPT_DIR/output/programa3
