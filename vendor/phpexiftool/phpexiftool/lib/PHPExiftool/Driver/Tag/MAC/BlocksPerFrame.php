<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\MAC;

use PHPExiftool\Driver\AbstractTag;

class BlocksPerFrame extends AbstractTag
{

    protected $Id = 2;

    protected $Name = 'BlocksPerFrame';

    protected $FullName = 'APE::NewHeader';

    protected $GroupName = 'MAC';

    protected $g0 = 'APE';

    protected $g1 = 'MAC';

    protected $g2 = 'Audio';

    protected $Type = 'int32u';

    protected $Writable = false;

    protected $Description = 'Blocks Per Frame';

}