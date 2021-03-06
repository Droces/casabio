<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\Ducky;

use PHPExiftool\Driver\AbstractTag;

class Comment extends AbstractTag
{

    protected $Id = 2;

    protected $Name = 'Comment';

    protected $FullName = 'APP12::Ducky';

    protected $GroupName = 'Ducky';

    protected $g0 = 'Ducky';

    protected $g1 = 'Ducky';

    protected $g2 = 'Image';

    protected $Type = 'string';

    protected $Writable = true;

    protected $Description = 'Comment';

    protected $flag_Avoid = true;

}
