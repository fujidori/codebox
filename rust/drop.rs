#![allow(unused)]
use std::fmt;

#[derive(Debug)]
struct HasDrop;

impl Drop for HasDrop {
    fn drop(&mut self) {
        println!("Dropping!");
    }
}

impl fmt::Display for HasDrop {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "(format)")
    }
}

fn main() {
    let _x = HasDrop;
    println!("{:?}", _x);
}
