#include <sasl/include/host/host_impl.h>

#include <sasl/include/host/shader_object_impl.h>
#include <sasl/include/host/shader_log_impl.h>

#include <sasl/include/common/diag_chat.h>
#include <sasl/include/common/diag_item.h>
#include <sasl/include/common/diag_formatter.h>
#include <sasl/include/driver/driver_api.h>
#include <sasl/include/codegen/jit_api.h>
#include <sasl/include/semantic/reflection_impl.h>

#include <fstream>

using boost::shared_ptr;

using std::cout;
using std::endl;
using std::fstream;
using std::string;
using std::vector;

using boost::shared_static_cast;
using boost::shared_dynamic_cast;
using boost::tuple;
using boost::make_shared;

using namespace salviar;
using namespace sasl::codegen;
using namespace sasl::common;
using namespace sasl::syntax_tree;
using namespace sasl::host;
using namespace sasl::semantic;

BEGIN_NS_SASL_HOST();

using salviar::shader_profile;
using salviar::render_parameters;

EFLIB_USING_SHARED_PTR(salviar, host);
EFLIB_USING_SHARED_PTR(salviar, input_layout);
EFLIB_USING_SHARED_PTR(salviar, shader_object);
EFLIB_USING_SHARED_PTR(salviar, shader_log);
EFLIB_USING_SHARED_PTR(salviar, vx_shader_unit);
EFLIB_USING_SHARED_PTR(salviar, px_shader_unit);
EFLIB_USING_SHARED_PTR(salviar, buffer);

/*
shader_code_impl::shader_code_impl(): pfn(NULL){
}

void shader_code_impl::abii( shared_ptr<shader_reflection> const& v ){
	abi = shared_dynamic_cast<reflection_impl>( v );
}

shader_reflection const* shader_code_impl::abii() const{
	return abi.get();
}

void shader_code_impl::jit( shared_ptr<jit_engine> const& v ){
	je = v;
}

void* shader_code_impl::function_pointer() const{
	return pfn;
}

void shader_code_impl::update_native_function(){
	assert( abi && je );
	if( !abi || !je ){
		pfn = NULL;
		return;
	}
	pfn = je->get_function( abi->entry_name() );
}
*/

END_NS_SASL_HOST();

using namespace sasl::host;
using namespace salviar;

salviar::host* salvia_create_host()
{
	assert(false);
	return NULL;
}

void salvia_compile_shader(
	shader_object_ptr& out_shader_object,
	shader_log_ptr& out_logs,
	shader_profile const& profile,
	std::string  const& code
	)
{
	out_shader_object.reset();
	
	boost::shared_ptr<sasl::driver::driver> drv;
	sasl_create_driver(drv);
	drv->set_code(code);

	const char* lang_name = NULL;
	switch(profile.language)
	{
	case lang_pixel_shader:
		lang_name = "--lang=ps";
		break;
	case lang_vertex_shader:
		lang_name = "--lang=vs";
		break;
	default:
		lang_name = "--lang=g";
		break;
	}

	drv->set_parameter(lang_name);
	shared_ptr<diag_chat> results = drv->compile();

	shader_log_impl_ptr log_impl = make_shared<shader_log_impl>();
	out_logs = log_impl;
	for(size_t i = 0; i < results->diag_items().size(); ++i)
	{
		log_impl->append(
			sasl::common::str(results->diag_items()[i])
			);
	}
	
	shader_object_impl_ptr ret( new shader_object_impl() );
	
	ret->set_reflection	( drv->get_reflection() );
	ret->set_vm_code	( drv->get_vmcode() );
	
	// Other members need to be set.
	assert(false);

	out_shader_object = ret;
	return;
}