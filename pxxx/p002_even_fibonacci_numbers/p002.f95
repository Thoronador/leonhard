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

program p002_even_fibonacci_numbers
  use divisible      ! provides isDivisibleBy(a, b)
  use fibonacci_1_2  ! provides the functions fibonacci_recursive() and fibonacci_iterative()
  implicit none

  integer :: i
  integer :: fibonacci_n
  integer :: fibonacci_sum

  fibonacci_sum = 0

  do i = 0, 999999
    fibonacci_n = fibonacci_iterative(i)
    if (fibonacci_n > 4000000) then
      ! break out of loop
      exit
    end if
    if (isDivisibleBy(fibonacci_n, 2)) then
      fibonacci_sum = fibonacci_sum + fibonacci_n
      write(*,*) "add ", fibonacci_n
    end if
  end do

  write(*,*) "The sum of all even Fibonacci numbers that do not exceed 4 million is ", fibonacci_sum, "."
end program p002_even_fibonacci_numbers
