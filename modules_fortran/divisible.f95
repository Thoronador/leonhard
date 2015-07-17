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
module divisible
  implicit none

  contains
    ! checks, if a is evenly divisible by b
    ! (Note: Yes, you don't need a function for that, you can just use MOD()
    !  instead and check it against zero directly, but I wanted to have an
    !  external function in a module to refresh how Fortran modules are written.
    logical function isDivisibleBy(a, b)
      integer, intent(in) :: a
      integer, intent(in) :: b

      isDivisibleBy = MOD(a, b) == 0

    end function isDivisibleBy

end module divisible
