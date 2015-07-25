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

program p009_special_pythagorean_triplet
  implicit none

  integer :: a, b, c

  do a = 3, 1000-2
    do b = a+1, 1000-1
      c = 1000 - a - b
      if (a*a+b*b==c*c) then
        write(*,*) "a:",a
        write(*,*) "b:",b
        write(*,*) "c:",c
        write(*,*) "Product a*b*c:", a*b*c
      end if
    end do
  end do

end program p009_special_pythagorean_triplet
