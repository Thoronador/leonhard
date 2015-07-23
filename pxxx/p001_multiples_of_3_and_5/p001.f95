! (C) 2015  Dirk Stolle
!
! This program is free software: you can redistribute it and/or modify
! it under the terms of the GNU General Public License as published by
! the Free Software Foundation, either version 3 of the License, or
! (at your option) any later version.
!
! This program is distributed in the hope that it will be useful,
! but WITHOUT ANY WARRANTY; without even the implied warranty of
! MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
! GNU General Public License for more details.
!
! You should have received a copy of the GNU General Public License
! along with this program.  If not, see <http://www.gnu.org/licenses/>.
!

program p001_multiples_3_5
  use divisible  ! provides the function isDivisibleBy()
  implicit none

  integer :: theSum
  integer :: i

  theSum = 0
  do i = 3, 1000-1
    if (isDivisibleBy(i, 3) .OR. isDivisibleBy(i, 5)) then
      theSum = theSum + i
    end if
  end do

  write(*,*) "The sum of all the multiples of 3 or 5 below 1000 is ", theSum, "."
end program p001_multiples_3_5
