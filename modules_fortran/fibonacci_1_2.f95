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
module fibonacci_1_2
  implicit none

  ! This module provides functions to calculate terms of the Fibonacci sequence
  ! that starts with 1, 2, 3, 5, 8, 13, 21, ...

  contains
    ! returns the n-th Fibonacci number, where n is the zero-based index
    recursive integer function fibonacci_recursive(a) result (res)
      integer, intent(in) :: a

      if (a == 0) then
        res = 1
      else if (a == 1) then
        res = 2
      else
        res = fibonacci_recursive(a-2) + fibonacci_recursive(a-1)
      end if
    end function fibonacci_recursive


    ! returns the n-th Fibonacci number, where n is the zero-based index
    integer function fibonacci_iterative(a)
      integer, intent(in) :: a
      integer :: i
      integer :: last
      integer :: last_but_one
      integer :: fibo

      if (a == 0) then
        fibonacci_iterative = 1
      else if (a == 1) then
        fibonacci_iterative = 2
      else
        last = 2
        last_but_one = 1

        do i=2, a
          ! add the both most recent numbers
          fibo = last + last_but_one
          ! shift older numbers
          last_but_one = last
          last = fibo
        end do
        ! return result
        fibonacci_iterative = fibo
      end if
    end function fibonacci_iterative
end module fibonacci_1_2
