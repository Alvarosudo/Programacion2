#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include <boost/signals2.hpp>
#include <string>
#include <iostream>
#include <cstdint>


using namechange_sig_t = boost::signals2::signal<void (const std::string&, const std::string&)>;

namespace P4 {

  template <typename T>
  class Container {

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const Container<U> &c);
    
  public:
    Container(const std::string& name="Container");
    virtual ~Container() = default;

    void set_name(const std::string& name);
    const std::string& get_name() const;
    void add(const T& item);
    void remove(const T& item);
    uint16_t find(const T& item) const;

    T& operator[](size_t i);
    size_t size() const;

  protected:
    std::string cname;
    std::vector<T> items;
  };

} // namespace P4
#include "container.tcc"

#endif /* CONTAINER_H */


