macro_rules! create_funtion {
    ($func_name:ident) => {
        fn $func_name() {
            println!("you called: {:?}()", stringify!($func_name));
        }
    };
}

create_funtion!(foo);
create_funtion!(bar);

macro_rules! print_result {
    ($expression:expr) => {
        println!("{:?} = {:?}", stringify!($expression), $expression);
    };
}

pub fn main() {
    foo();
    bar();
    print_result!(1u32 + 1);

    print_result!({
        let x = 1u32;
        x * x + 2 * x - 1
    });
}
