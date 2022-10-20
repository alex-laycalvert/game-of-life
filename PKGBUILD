# Maintainer: Alex Lay-Calvert <alex.laycalvert@gmail.com>
pkgname=game-of-life
pkgver=1.0.0
pkgrel=1
pkgdesc="An implementation of John Conway's Game of Life"
arch=(x86_64)
url="github.com/alex-laycalvert/game-of-life.git"
license=('MIT')
groups=()
depends=('ncurses')
makedepends=()
optdepends=()
provides=()
conflicts=()
replaces=()
backup=()
options=()
install=
changelog=
source=(git+https://$url)
noextract=()
md5sums=("SKIP")
build() {
    cd "$pkgname"
    make
}
package() {
    cd "$pkgname"
    ls -l
    cat makefile
    make DESTDIR="$pkgdir/" install
}
