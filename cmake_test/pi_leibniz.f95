! (C) 2009, 2011 Dirk Stolle
!
! This programme calculates an approximate value for Pi using the formula from
! Leibniz:
!
! Pi/4 = Sum((-1)^n/(2n+1), n=0 to infinity)
!
! Since this sum has an infinite number of summands, it stops as soon as the
! value does not change any more, compared to the last iteration. It can also
! stop if the given (constant) number of iteration steps is exceeded, but on
! usual desktop systems the full number of steps is not needed, because the
! precision of real type is too low and we always run into the other condition
! first.

program pi_leibniz
  implicit none

  real(kind=8) :: pi4, last_value
  integer :: i
  integer, parameter :: max_steps = 1250000000

  write(*,*) 'Calculating Pi (Leibniz method)'
  pi4=0.0
  last_value = pi4
  do i = 1, max_steps, 4
    pi4 = pi4 +1.0/real(i)-1.0/real(i+2)
    if (pi4==last_value) then
      write(*,*) 'Breaking out of loop, because the value does not change any more.'
      exit
    endif
    last_value = pi4
    if (mod(i-1,1000000)==0) write(*,*) "Pi after ", i/2, " steps:" , pi4*4
  end do
  write(*,*) "Pi after ", i/2, " steps:" , pi4*4
end program pi_leibniz
