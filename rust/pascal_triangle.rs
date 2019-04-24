fn pascal() {
    const N: usize = 15;
    let mut table = [[1; N]; N];
    for i in 2..N {
        for j in 1..i {
            table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
        }
    }
    for i in 0..N {
        for j in 0..i + 1 {
            print!("{} ", table[i][j]);
        }
        println!("");
    }
}

fn main() {
    pascal();
}
