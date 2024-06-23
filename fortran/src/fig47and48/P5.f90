! ESTRELA HÍBRIDA
 ! Programa para calcular a massa e a pressão como funções do raio , do centro da estrela até a a superfície , onde p = 0. Neste ponto , o programa para , imprimindo o raio total e a massa total da estrela na tela .
MODULE global
  IMPLICIT NONE
 ! pi , velocidade da luz no vácuo , constante reduzida de Planck , massa de um núcleon
  REAL , PARAMETER :: pi = 4.* atan (1.0) , c = 2.99792458d23 , hbar = 6.58211915d-25 , mn = 0.938 ! [ c ] = fm /s , [ hbar ] = GeV . s , [ mn ] = GeV
  ! R0 = G * Msol / c ^2 // G = 6.67408 d-11 , Msol = 1.989 d30 ![ G ] = m ^3 kg ^ -1 s ^ -2 , [ Msol ] = kg
  REAL , PARAMETER :: R0 = 1.47611 ! km
  ! M0 = 10^54/(6 ,242 d9 * Msol * c **2) ! incluindo a conversão de m ^3 para fm ^3
  REAL , PARAMETER :: M0 = 8.9616d-4 ! GeV
  ! pressão de sacola
  REAL , PARAMETER :: B = 0.185**4 ! GeV ^4
  ! densidade bariônica nuclear
  REAL , PARAMETER :: n0 = 1.2277d-3 ! GeV ^3 // n0 = 0.16 fm ^ -3
  ! compressibilidade , energia de ligação , energia de simetria
  REAL , PARAMETER :: K = 0.17 , W0 = -.016 , Wsym = 0.032 ! GeV
END MODULE global

PROGRAM hybridstar
  USE global
  IMPLICIT NONE
  ! raio , passo do raio
  REAL :: r , dr = 1d-3 ! km
  ! massa // mi evita a divisão por zero na equação TOV
  REAL :: m , mi = 1d-3 ! Msol
  ! pressão , densidade de energia
  REAL :: p , e ! GeV ^4
  ! densidade bariônica , densidade bariônica central , densidade bariônica crítica ( transição de fase )
  REAL :: n , nc , ncrit ! GeV ^3
  10 format ( E14.7, 1x, E14.7, 1x, E14.7, 1x, E14.7)
  11 format (1x , A, 14x, A, 14x, A, 14x, A)

  nc = 8*n0
  ! cálculo da densidade crítica
  ! transição de fase ocorre quando a pressão da matéria hadrônica for igual a B
  ncrit = 4*n0 ! palpite
  CALL newton(B, ncrit)

  ! condições iniciais
  n = nc
  p = 3* pi **(2/3.) * n **(4/3.) /4. - B
  e = 3* p + 4* B
  r = 0d0
  m = 0d0
  mi = 1d-3 ! evita divisão por zero

  OPEN (10 , FILE = 'data/Fig47and48_P5.dat ')
  ! WRITE (10 ,11) 'r ' , 'p ' , 'e ' , 'm '
  WRITE (10 ,10) r , p *1d3 /( hbar * c ) **3 , e *1d3 /( hbar * c ) **3 , m ![ r ] = km , [ p ] = [ e ] = MeV / fm ^3 , [ m ] = Msol

  DO WHILE ( p > 0d0 )
    IF ( n >= ncrit ) THEN
      CALL quark (p , e , n )
    ELSE
      CALL neutron (p , e , n )
    END IF
    r = r + dr
    p = - R0 * e * m * dr / r **2.*(1.+ p / e ) *(1.+4.* pi * r **3.* p * M0 / mi ) /(1. -2.* R0 * m / r ) + p ! integração da TOV
    m = 4.* pi * r **2.* e * dr * M0 /( hbar * c ) **3 + m ! integração da massa
    mi = m
    WRITE (10 ,10) r , p *1d3 /( hbar * c ) **3 , e *1d3 /( hbar * c ) **3 , m ! [ r ] = km , [ p ] = [ e ] = MeV / fm ^3 , [ m ] = Msol
  END DO
  CLOSE (10)
  PRINT * , r , m
END PROGRAM hybridstar


SUBROUTINE quark (p , e , n )
  USE global
  IMPLICIT NONE
  REAL :: p , e
  REAL :: n

  e = 3* p + 4* B ! GeV ^4
  n = (4*( p + B ) /(3* pi **(2/3.) ) ) **(3/4.)! GeV ^3

END SUBROUTINE quark


SUBROUTINE neutron (p , e , n )
  USE global
  IMPLICIT NONE
  REAL :: p , e
  REAL :: n
  CALL newton (p , n )
  e = n *( K /18.*( n - n0 ) **2/ n0 **2 + W0 + Wsym + mn )
END SUBROUTINE neutron


SUBROUTINE newton (p , ni )
  USE global
  IMPLICIT NONE
  REAL :: pn , p , dpdn
  REAL :: n , ni
  DO
  n = ni - pn ( ni , p ) / dpdn ( ni )
  IF ( abs ( pn ( ni , p ) ) <= 1d-11) EXIT
  ni = n
  END DO
END SUBROUTINE newton


REAL FUNCTION pn (n , p )
  USE global
  IMPLICIT NONE
  REAL :: n , p
  pn = K /9.*( n - n0 ) *( n / n0 ) **2 - p
END FUNCTION pn


REAL FUNCTION dpdn ( n )
  USE global
  IMPLICIT NONE
  REAL :: n
  dpdn = K /9.*(3*( n / n0 ) - 2) * n / n0
END FUNCTION dpdn
