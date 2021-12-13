// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: FullName.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_FullName_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_FullName_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3017000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3017001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_FullName_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_FullName_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_FullName_2eproto;
namespace Proto {
class FuLLName;
struct FuLLNameDefaultTypeInternal;
extern FuLLNameDefaultTypeInternal _FuLLName_default_instance_;
}  // namespace Proto
PROTOBUF_NAMESPACE_OPEN
template<> ::Proto::FuLLName* Arena::CreateMaybeMessage<::Proto::FuLLName>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Proto {

// ===================================================================

class FuLLName final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Proto.FuLLName) */ {
 public:
  inline FuLLName() : FuLLName(nullptr) {}
  ~FuLLName() override;
  explicit constexpr FuLLName(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  FuLLName(const FuLLName& from);
  FuLLName(FuLLName&& from) noexcept
    : FuLLName() {
    *this = ::std::move(from);
  }

  inline FuLLName& operator=(const FuLLName& from) {
    CopyFrom(from);
    return *this;
  }
  inline FuLLName& operator=(FuLLName&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const FuLLName& default_instance() {
    return *internal_default_instance();
  }
  static inline const FuLLName* internal_default_instance() {
    return reinterpret_cast<const FuLLName*>(
               &_FuLLName_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(FuLLName& a, FuLLName& b) {
    a.Swap(&b);
  }
  inline void Swap(FuLLName* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(FuLLName* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline FuLLName* New() const final {
    return new FuLLName();
  }

  FuLLName* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<FuLLName>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const FuLLName& from);
  void MergeFrom(const FuLLName& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(FuLLName* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Proto.FuLLName";
  }
  protected:
  explicit FuLLName(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 1,
    kSurnameFieldNumber = 2,
    kPatronymicFieldNumber = 3,
  };
  // string Name = 1;
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_FUTURE_MUST_USE_RESULT std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // string Surname = 2;
  void clear_surname();
  const std::string& surname() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_surname(ArgT0&& arg0, ArgT... args);
  std::string* mutable_surname();
  PROTOBUF_FUTURE_MUST_USE_RESULT std::string* release_surname();
  void set_allocated_surname(std::string* surname);
  private:
  const std::string& _internal_surname() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_surname(const std::string& value);
  std::string* _internal_mutable_surname();
  public:

  // optional string Patronymic = 3;
  bool has_patronymic() const;
  private:
  bool _internal_has_patronymic() const;
  public:
  void clear_patronymic();
  const std::string& patronymic() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_patronymic(ArgT0&& arg0, ArgT... args);
  std::string* mutable_patronymic();
  PROTOBUF_FUTURE_MUST_USE_RESULT std::string* release_patronymic();
  void set_allocated_patronymic(std::string* patronymic);
  private:
  const std::string& _internal_patronymic() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_patronymic(const std::string& value);
  std::string* _internal_mutable_patronymic();
  public:

  // @@protoc_insertion_point(class_scope:Proto.FuLLName)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr surname_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr patronymic_;
  friend struct ::TableStruct_FullName_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// FuLLName

// string Name = 1;
inline void FuLLName::clear_name() {
  name_.ClearToEmpty();
}
inline const std::string& FuLLName::name() const {
  // @@protoc_insertion_point(field_get:Proto.FuLLName.Name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void FuLLName::set_name(ArgT0&& arg0, ArgT... args) {
 
 name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Proto.FuLLName.Name)
}
inline std::string* FuLLName::mutable_name() {
  // @@protoc_insertion_point(field_mutable:Proto.FuLLName.Name)
  return _internal_mutable_name();
}
inline const std::string& FuLLName::_internal_name() const {
  return name_.Get();
}
inline void FuLLName::_internal_set_name(const std::string& value) {
  
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* FuLLName::_internal_mutable_name() {
  
  return name_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* FuLLName::release_name() {
  // @@protoc_insertion_point(field_release:Proto.FuLLName.Name)
  return name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void FuLLName::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:Proto.FuLLName.Name)
}

// string Surname = 2;
inline void FuLLName::clear_surname() {
  surname_.ClearToEmpty();
}
inline const std::string& FuLLName::surname() const {
  // @@protoc_insertion_point(field_get:Proto.FuLLName.Surname)
  return _internal_surname();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void FuLLName::set_surname(ArgT0&& arg0, ArgT... args) {
 
 surname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Proto.FuLLName.Surname)
}
inline std::string* FuLLName::mutable_surname() {
  // @@protoc_insertion_point(field_mutable:Proto.FuLLName.Surname)
  return _internal_mutable_surname();
}
inline const std::string& FuLLName::_internal_surname() const {
  return surname_.Get();
}
inline void FuLLName::_internal_set_surname(const std::string& value) {
  
  surname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* FuLLName::_internal_mutable_surname() {
  
  return surname_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* FuLLName::release_surname() {
  // @@protoc_insertion_point(field_release:Proto.FuLLName.Surname)
  return surname_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void FuLLName::set_allocated_surname(std::string* surname) {
  if (surname != nullptr) {
    
  } else {
    
  }
  surname_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), surname,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:Proto.FuLLName.Surname)
}

// optional string Patronymic = 3;
inline bool FuLLName::_internal_has_patronymic() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool FuLLName::has_patronymic() const {
  return _internal_has_patronymic();
}
inline void FuLLName::clear_patronymic() {
  patronymic_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& FuLLName::patronymic() const {
  // @@protoc_insertion_point(field_get:Proto.FuLLName.Patronymic)
  return _internal_patronymic();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void FuLLName::set_patronymic(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000001u;
 patronymic_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Proto.FuLLName.Patronymic)
}
inline std::string* FuLLName::mutable_patronymic() {
  // @@protoc_insertion_point(field_mutable:Proto.FuLLName.Patronymic)
  return _internal_mutable_patronymic();
}
inline const std::string& FuLLName::_internal_patronymic() const {
  return patronymic_.Get();
}
inline void FuLLName::_internal_set_patronymic(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  patronymic_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* FuLLName::_internal_mutable_patronymic() {
  _has_bits_[0] |= 0x00000001u;
  return patronymic_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* FuLLName::release_patronymic() {
  // @@protoc_insertion_point(field_release:Proto.FuLLName.Patronymic)
  if (!_internal_has_patronymic()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return patronymic_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void FuLLName::set_allocated_patronymic(std::string* patronymic) {
  if (patronymic != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  patronymic_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), patronymic,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:Proto.FuLLName.Patronymic)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace Proto

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_FullName_2eproto