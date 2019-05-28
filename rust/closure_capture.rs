fn main() {
    use std::mem;
    let color = "green";

    let print = || println!("color: {}", color);

    print();
    print();

    let mut count = 0;

    let mut inc = || {
        count += 1;
        println!("count: {}", count);
    };

    inc();
    inc();
}
