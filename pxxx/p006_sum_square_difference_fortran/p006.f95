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

program p006_sum_square_difference
  implicit none

  integer :: i
  integer :: sum_of_squares = 0
  integer :: sum = 0
  integer :: square_of_sum = 0

  do i = 1, 100
    sum_of_squares = sum_of_squares + i*i
    sum = sum + i
  end do

  square_of_sum = sum**2

  write(*,*) "Sum of squares: ", sum_of_squares
  write(*,*) "Square of sum:  ", square_of_sum
  write(*,*) "Difference: " , square_of_sum - sum_of_squares

end program p006_sum_square_difference
